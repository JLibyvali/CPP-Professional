#include "debug.h"

#include <condition_variable>
#include <cstring>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

bool                    flag_msg;
std::condition_variable msg_cond;
std::mutex              msg_mut;
std::queue<std::string> message;

void                    in()
{

    std::string str;
    str.reserve(128);

    while (1)
    {
        std::cout << "Input message: \n";
        std::cin >> str;

        if (str == "q")
        {
            std::lock_guard lk{msg_mut};
            flag_msg = true;
            msg_cond.notify_all();
            break;
        }

        std::lock_guard msg_lock(msg_mut);
        message.push(str);
        flag_msg = true;
        msg_cond.notify_all();

        str.clear();
    }

    std::cout << "Exit..........." << std::endl;
}

void handle()
{
    std::string msg;

    while (true)
    {
        std::unique_lock lk{msg_mut};
        msg_cond.wait(lk, [] { return (flag_msg); });

        if (!message.empty())
        {
            msg = message.front();
            message.pop();

            std::cout << "Finished handling: " << RED << msg << NONE << std::endl;
        }
        else
        {
            break;
        }

        flag_msg = false;
        msg.clear();
    }

    std::cout << "Handler exit..........." << std::endl;
}

int main()
{
    std::cout << "Test read/write buffer" << std::endl;
    std::thread th_r{in};
    std::thread th_handler{handle};

    th_r.join();
    th_handler.detach();

    return 0;
}