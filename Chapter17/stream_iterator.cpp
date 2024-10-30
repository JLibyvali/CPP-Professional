#include <iostream>
#include <iterator>
#include <type_traits>
#include <vector>

// stream_iterator can traverse IO stream like iterator
// Using ostream_iterator
template <typename Iterator, typename Target> void output(Iterator _beign, Iterator _end, Target _out)
{
    using os_iter_type = decltype(_out);

    if constexpr (std::is_same<os_iter_type, std::ostream_iterator<int>>::value)
    {
        // If int iterator
        for (_beign; _beign != _end; ++_beign)
        {
            *_out = *(_beign) + 1;
        }
    }
    else
    {
        // If bool iterator
        for (_beign; _beign != _end; ++_beign)
        {
            *_out = *_beign;
        }
    }
}

int main()
{
    std::vector<int>  ints(10);
    std::vector<bool> bools(10);

    // Assigned
    for (int i = 0; i < 10; i++)
    {
        ints[i] = i;

        if (i & 1)
            bools[i] = 1;
        else
            bools[i] = 0;
    }

    std::cout << "Test stream_iterator" << std::endl;
    auto os_int_it = std::ostream_iterator<int>(std::cout, "");

    std::cout << "Int ostream_iterator" << std::endl;
    output(ints.cbegin(), ints.cend(), os_int_it);
    std::cout << std::endl;
    output(ints.rbegin(), ints.rend(), os_int_it);
    std::cout << std::endl;

    std::cout << "Bool ostream_iterator" << std::endl;
    auto os_bool_it = std::ostream_iterator<bool>(std::cout << std::boolalpha, "\n");
    output(bools.cbegin(), bools.cend(), os_bool_it);
    std::cout << std::endl;

    return 0;
}