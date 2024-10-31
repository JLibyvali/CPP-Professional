#include "debug.h"

#include <atomic>
#include <bitset>
#include <chrono>
#include <ctime>
#include <format>
#include <ios>
#include <iostream>
#include <iterator>
#include <thread>
#include <type_traits>
#include <unistd.h>
#include <vector>

class Data_1
{
public:

    int m_id;
};

class Data_2
{
public:

    int m_arr[10][20];
};

// shared resource
std::atomic<int> cnt = 0;

void             inc(std::atomic<int> &_val)
{
    int res = 0;
    for (int i = 0; i < 10; i++)
    {
        res += i;
    }
    _val.fetch_add(res);
}

int main()
{
    // Test atomic class
    std::cout << std::boolalpha << "Is lock free? " << cnt.is_lock_free() << std::endl;

    // Test can be atomic?
    std::cout << std::boolalpha
              << "Can used as atomic? Data_1: " << std::is_trivially_copyable_v<Data_1> << " And Data_2: "
              << std::is_trivially_copyable_v<Data_2> << std::endl;

    for (int i = 0; i < 10; i++)
    {
        std::thread tmp{inc, std::ref(cnt)};
        tmp.join();
    }

    std::cout << "Final result: " << cnt
              << "\033[1;31m"
                 "\nCase used atomic, doesn't need Manually synchronous"
                 "\033[0m"
              << std::endl;

    return 0;
}
