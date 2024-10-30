#include <chrono>
#include <ctime>
#include <format>
#include <iostream>
#include <ratio>

void time_d()
{
    // duration<Repeat type, Repeat period>  obj{Repeat Times}

    std::chrono::duration<long, std::ratio<1>>     d_10s{10};
    std::chrono::duration<long, std::ratio<1, 60>> d_3s{180};
    std::chrono::duration<long, std::milli>        d_1s{1000};

    std::cout << std::format(
                     "Repeat d_10s:{},{}  d_3s:{},{}  d_1s:{},{}", d_10s.count(), std::chrono::seconds(d_10s),
                     d_3s.count(), std::chrono::duration_cast<std::chrono::seconds>(d_3s), d_1s.count(),
                     std::chrono::duration_cast<std::chrono::seconds>(d_1s)
                 )
              << std::endl;
}

int main()
{
    std::cout << "Duration time" << std::endl;

    time_d();
    return 0;
}