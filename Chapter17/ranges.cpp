#include <algorithm>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct Test
{
    std::string str = "Hello";
};

int main()

{
    // Range and view
    // Range can  always with callback
    std::vector<Test> vecs(12);
    for (int i = 10; i > 0; i--)
    {
        std::string tmp = "  TEST: ";
        tmp.append(std::to_string(i));

        vecs[i].str.append(tmp);
    }

    std::ranges::sort(vecs, {}, &Test::str);
    std::ranges::for_each(vecs, [](const Test &_ele) { std::cout << _ele.str << std::endl; });

    return 0;
}