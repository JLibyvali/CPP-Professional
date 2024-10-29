#include <boost/asio.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iomanip>
#include <iostream>

int main()
{
    // Test timer
    std::cout<<"Waiting timer.................."<<std::endl;
    boost::asio::io_context   io_ctl;
    // init a steady_timer
    boost::asio::steady_timer timer{io_ctl, std::chrono::seconds(3)};
    timer.wait();  // After created 4 seconds

    std::cout << "Timer " << std::chrono::duration_cast<std::chrono::seconds>(timer.expiry().time_since_epoch())
              << " finished" << std::endl;
    return 0;
}