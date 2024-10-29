#include <boost/asio.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>
#include <boost/system/detail/error_code.hpp>
#include <chrono>
#include <cstdio>
#include <iostream>

// handler
void print(const boost::system::error_code &er) { std::cout << "Asynchronous handler" << std::endl; }

int  main()
{

    printf("Waiting timer..........\n");
    boost::asio::io_context   io;
    boost::asio::steady_timer timer(io, std::chrono::seconds(3));

    timer.async_wait(&print);
    printf("The asynchronous wait return......\n");
    io.run();

    return 0;
}
