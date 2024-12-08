#include <algorithm>
#include <iostream>
import Hello;
import Sort;

int main()
{
    Hello();
    World();

    std::cout << "#############3 Test Module Partition. ###########3" << std::endl;
    auto num       = init_data(100);

    auto print_num = [&](data_t &_t)
    {
        std::cout << "@@@@@@@@ Output: ";
        std::cout << "Random nums\n";

        for (const int &ele : _t.first)
        {
            std::cout << ele << ",";
        }

        std::cout << "\nReverse nums: \n";
        for (const int &ele : _t.second)
        {
            std::cout << ele << ",";
        }
        std::cout << std::endl;
    };

    print_num(num);
    m_sort::qs_3(num.first);

    std::cout << "########### After Sort ##################" << std::endl;
    print_num(num);

    std::sort(num.first.begin(),num.first.end());
    std::cout << "########### Standard sort #################3" << std::endl;
    print_num(num);

    return 0;
}