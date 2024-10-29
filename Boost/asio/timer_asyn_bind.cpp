#include <boost/asio.hpp>
#include <boost/asio/placeholders.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <functional>
#include <iostream>

void print(const boost::system::error_code &er, boost::asio::steady_timer *tm, int *cnt)
{

    if (*cnt < 5)
    {
        std::cout << std::format(
                         "Timers expired time point: {}, expired duration: {}",
                         std::chrono::duration_cast<std::chrono::seconds>(tm->expires_at().time_since_epoch()),
                         tm->expires_from_now()
                     )
                  << std::endl;
        std::cout << "Count " << *cnt << std::endl;
        tm->expires_at(tm->expiry() + std::chrono::seconds(1));

        tm->async_wait(std::bind(print, std::placeholders::_1, tm, cnt));
        std::cout << "Created new timer, asynchronous wait return\n" << std::endl;

        (*cnt)++;
    }
}

int main()
{

    // test timer
    std::cout << "Using std::bind()" << std::endl;
    boost::asio::io_context   io;
    boost::asio::steady_timer timer{io, std::chrono::seconds(3)};

    int                       count = 0;
    timer.async_wait(std::bind(print, std::placeholders::_1, &timer, &count));
    io.run();

    std::cout << "Final count: " << count << std::endl;
    return 0;
}
