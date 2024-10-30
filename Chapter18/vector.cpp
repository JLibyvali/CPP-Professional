#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

int main()
{

    // Test vector size capacity
    auto os_iter{std::ostream_iterator<std::string_view>(std::cout, " ; ")};
    
    std::cout << "\033[1;31m"
                 "Test vector memory size"
                 "\033[0m"
              << std::endl;
    std::vector<std::string> vecs;
    // vecs.reserve(10);

    std::string              str{"Hello"};
    std::cout << "Str char nums: " << str.size() << "; bytes:" << str.capacity() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        str.append(" IDX: ");
        str.append(std::to_string(i));

        vecs.push_back(str);

        str = "Hello";
    }

    std::cout << "Str char nums: " << str.size() << "; Capacity to hold element: " << str.capacity()
              << ";Bytes: " << str.capacity() * sizeof(str[0]) << std::endl;
    std::cout << "Vecs element nums: " << vecs.size() << "; Capacity to hold element: " << vecs.capacity()
              << "; Bytes: " << vecs.capacity() * sizeof(vecs[0]) << std::endl;

    // Output
    std::for_each(vecs.cbegin(), vecs.cend(), [&](const std::string_view &_str) { *os_iter = _str; });
    std::cout << std::endl;

    // CLear only clear  elements, not free the memory
    vecs.clear();
    std::cout << "\033[1;31m"
                 "After Clear Vecs element nums: "
              << vecs.size() << "; Capacity to hold element: " << vecs.capacity()
              << "; Bytes: "
                 "\033[0m" <<
        vecs.capacity() * sizeof(vecs[0]) << std::endl;
    std::for_each(vecs.cbegin(), vecs.cend(), [&](const std::string_view &_str) { *os_iter = _str; });
    std::cout << std::endl;

    // Free memory use swap
    std::vector<std::string>().swap(vecs);
    std::cout << "\033[1;31m""After swap Vecs element nums: " << vecs.size() << "; Capacity to hold element: " << vecs.capacity()
              << "; Bytes: ""\033[0m" << vecs.capacity() * sizeof(vecs[0]) << std::endl;

    return 0;
}