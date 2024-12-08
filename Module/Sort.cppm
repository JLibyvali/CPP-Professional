module;
#include <utility>
#include <vector>
export module Sort;

export import :interface;
import :impl;

export using data_t = std::pair<std::vector<int>, std::vector<int>>;

export data_t init_data(int _n);