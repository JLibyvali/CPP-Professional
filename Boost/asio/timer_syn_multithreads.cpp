#include <boost/asio.hpp>
#include <boost/asio/detail/chrono.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/strand.hpp>
#include <chrono>
#include <format>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>

static auto current = std::chrono::steady_clock::now();

class Printer
{
public:

    explicit Printer(boost::asio::io_context &io, size_t _max) : m_max(_max), m_strand(boost::asio::make_strand(io))
    {
        // Create 10 timers.
        for (int i = 0; i < m_max; i++)
        {
            m_timers.push_back(boost::asio::steady_timer{io, std::chrono::seconds(1)});
        }

        for (int i = 0; i < m_timers.size(); i++)
        {
            // std::bind will bind Printer::print as timer's handler
            // boost::asio::bind_executor will bind the handler to executor
            // Then io::run, it will the Keep synchronous order.
            m_timers[i].async_wait(
                boost::asio::bind_executor(m_strand, std::bind(&Printer::print, this, std::placeholders::_1, i))
            );
        }
    }

private:

    // handler
    void   print(const boost::system::error_code &er, int idx);

    size_t m_cnt = 0;  // Shared resources
    size_t m_max;
    boost::asio::strand<boost::asio::io_context::executor_type>
        m_strand;      //  strand is a executor adapter, handling all treads under `io_context` object.
    std::vector<boost::asio::steady_timer> m_timers;
};

void Printer::print(const boost::system::error_code &er, int idx)
{

    if (m_cnt < m_max)
    {

        auto live = std::chrono::duration_cast<std::chrono::milliseconds>(m_timers[idx].expiry() - current);

        std::cout << std::format("Timer {}  Expired time since Program-Begin {}, repeat time {}", idx, live,m_cnt) << std::endl;
        m_cnt++;

        // Restart the timer
        m_timers[idx].expires_at(m_timers[idx].expiry() + std::chrono::seconds(1));

        m_timers[idx].async_wait(
            boost::asio::bind_executor(m_strand, std::bind(&Printer::print, this, std::placeholders::_1, idx))
        );
    }
}

int main()
{

    std::cout << "Waiting multi threads............" << std::endl;
    boost::asio::io_context io;
    Printer                 p(io, 10);

    std::thread             th{[&] { io.run(); }};
    th.join();

    return 0;
}