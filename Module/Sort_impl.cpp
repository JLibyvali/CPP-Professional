module;
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
module Sort;

data_t init_data(int _n)
{
    data_t             res{_n, _n};
    std::random_device rd_device;
    auto seed{rd_device.entropy() ? rd_device() : std::chrono::high_resolution_clock::now().time_since_epoch().count()};
    std::mt19937_64                    rd_engine(seed);
    std::uniform_int_distribution<int> rd_dis(1, 100);

    for (int i = 0; i < _n; i++)
    {
        res.first[i]  = rd_dis(rd_engine);
        res.second[i] = _n - i;
    }
    return res;
}