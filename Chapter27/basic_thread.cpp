#include "debug.h"
#include <chrono>
#include <exception>
#include <format>
#include <iostream>
#include <stdexcept>
#include <thread>

void work()
{
    std::cout << "Will throw  exception" << std::endl;
    throw std::runtime_error{"Test exception"};
}

void thread_func(std::exception_ptr &er)
{
    try
    {
        work();
    }
    catch (...)
    {
        std::cout << "Exception caught, return it" << std::endl;
        er = std::current_exception();
    }

    return;
}

void test()
{
    std::exception_ptr ex;
    std::thread        th_01{thread_func, std::ref(ex)};
    th_01.join();

    // Check exception return
    if (ex)
        std::rethrow_exception(ex);
    else
        std::cout << "None exception from thread" << std::endl;
}

int main()
{

    std::cout << "Test for thread exception" << std::endl;

    try
    {
        test();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Main thread caught exception: "<<RED<< ex.what() <<NONE<< std::endl;
    }

    return 0;
}
