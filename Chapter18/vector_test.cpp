#include "debug.h"
#include "vector_perf.h"

#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

int main()

{

    // Time complexity
    std::cout << FMT("Test vector efficient and performance", BLACK) << std::endl;

    std::vector<int> int_vec;
    test::Perf_test  perf{int_vec, 0x3f3f3f};

    // perf.test_find();
    perf.test_insert();
    // perf.test_delete();
    return 0;
}