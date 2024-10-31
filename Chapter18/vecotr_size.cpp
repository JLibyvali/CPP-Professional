
#include "debug.h"
#include "vector_perf.h"

#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

int main()

{

    // Test vector size capacity
    auto print_vec = [](const std::vector<std::string> &_vec)
    {
        auto os_iter{std::ostream_iterator<std::string_view>(std::cout << FMT("Elements: ", RED), " ; ")};

        for (const auto &ele : _vec)
        {
            *os_iter = ele;
        }
        std::cout << std::endl;
    };

    std::cout << FMT("Test vector memory usage", BLACK) << std::endl;
    std::vector<std::string> str_vecs;
    // vecs.reserve(10);

    std::string              str{"Hello"};
    std::cout << "Str char nums: " << str.size() << "; Capacity to hold element: " << str.capacity()
              << ";Bytes: " << str.capacity() * sizeof(str[0]) << std::endl;

    // Assign
    for (int i = 0; i < 10; i++)
    {
        str.append(" IDX: ");
        str.append(std::to_string(i));

        str_vecs.push_back(str);

        str = "Hello";
    }
    test::vec_space(str_vecs, "After push_back");
    print_vec(str_vecs);

    // CLear only clear  elements, not free the memory
    str_vecs.clear();
    test::vec_space(str_vecs, "After clear");
    print_vec(str_vecs);

    // Free memory use swap with empty vector
    std::vector<std::string>().swap(str_vecs);
    test::vec_space(str_vecs, "After swap with empty vecotr");

    str_vecs.reserve(1);
    test::vec_space(str_vecs, "Reserve again");

    str_vecs.push_back("Element 1");
    test::vec_space(str_vecs);
    str_vecs.emplace_back("Element 3");
    test::vec_space(str_vecs);
    str_vecs.emplace_back("Element 3");
    test::vec_space(str_vecs);

    std::cout << "Trigger realloc memory" << std::endl;

    std::vector<std::string>().swap(str_vecs);

}