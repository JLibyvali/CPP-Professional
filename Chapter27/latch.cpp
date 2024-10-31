#include "debug.h"

#include <chrono>
#include <condition_variable>
#include <iostream>
#include <latch>
#include <mutex>
#include <string>
#include <thread>

/**
 * @brief Latch is a counter to synchronous Multi threads work
 * When the counter==0, the `latch` will be always signal state
 * some blocking state will run;
 * And barrier will call the callback
 */



std::latch              msg_latch{10};

bool                    flag_res;
std::condition_variable cond_res;
std::mutex              str_mut;
std::string             str;

void                    worker(int _id)
{
    std::cout << "Worker id: " << _id << " is Working." << std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(50));  // simulate some works
    std::string                  res = "Works from [" + std::to_string(_id) + "]\n";

    std::unique_lock<std::mutex> lk{str_mut};
    str.append(res);
    lk.unlock();

    msg_latch.arrive_and_wait();

    lk.lock();
    cond_res.wait(lk, [] { return flag_res; });

    std::cout << "Worker id: " << _id << "Exit................" << std::endl;
}

void res()
{
    std::cout << "Final res handling............." << std::endl;
    msg_latch.wait();

    std::lock_guard lk{str_mut};
    str.append(FMT("{RESULT}", RED));
    flag_res = true;
    cond_res.notify_all();
}

int main()
{
    int workerS = 10;
    str.clear();

    for (int i = 0; i < workerS; i++)
    {
        std::thread th_work{worker, i};
        th_work.detach();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::thread res_th{res};
    res_th.join();

    std::cout<<"############RESULT\n";
    std::cout << str << std::endl;

    return 0;
}