#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/system/detail/error_code.hpp>
#include <chrono>
#include <cstddef>
#include <format>
#include <functional>
#include <iostream>

class Printer
{
public:

    explicit Printer(boost::asio::io_context &_context, int _cnt)
        : m_max(_cnt), m_timer(_context, std::chrono::seconds(1))
    {}

    // wait
    void init_wait() { m_timer.async_wait(std::bind(&Printer::print, this, std::placeholders::_1)); }

private:

    // handler
    void                      print(const boost::system::error_code &);

    size_t                    m_cnt = 0;
    size_t                    m_max;
    boost::asio::steady_timer m_timer;
};

void Printer::print(const boost::system::error_code &er)
{

    if (m_cnt < m_max)
    {
        std::cout << std::format(
                         "Timer \"{}\" expired time: {}, expired time duration relative now: {}", m_cnt,
                         std::chrono::duration_cast<std::chrono::minutes>(m_timer.expiry().time_since_epoch()),
                         m_timer.expires_from_now()
                     )
                  << std::endl;
        m_cnt++;

        // Set timer's expired time is current time point plus 1sec
        m_timer.expires_at(m_timer.expiry() + std::chrono::seconds(1));
        m_timer.async_wait(std::bind(&Printer::print, this, std::placeholders::_1));
    }
}

int main()
{

    // test timer
    std::cout << "Begin timer......." << std::endl;
    boost::asio::io_context io;
    Printer                 pt(io, 10);
    pt.init_wait();

    io.run();

    return 0;
}