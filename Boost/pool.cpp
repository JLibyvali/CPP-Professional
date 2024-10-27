#include "debug.h"

#include <boost/pool/object_pool.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <cstdio>
#include <cstdlib>
#include <format>
#include <iostream>
#include <memory>
#include <utility>

class Demo
{
public:

    Demo() : Demo(1, 1, 1) {}

    Demo(int a, int b, int c) : m_a(a), m_b(b), m_c(c) {}

    int         m_a, m_b, m_c;
    std::string m_str = "hello world.";
};

int main()
{
    // test for pool, pool only for basic type
    printf(ANSI_FMT("Test for normal pool \n", ANSI_BLUE));
    boost::pool<> int_pool(10 * sizeof(int));
    char         *buf = static_cast<char *>(malloc(10 * sizeof(char)));

    std::cout << std::format(
                     ANSI_FMT("Pool every time request block size {}, Maxsize: {} , Nextsize: {}", ANSI_BLUE),
                     int_pool.get_requested_size(), int_pool.get_max_size(), int_pool.get_next_size()
                 )
              << std::endl;

    int *arr = static_cast<int *>(int_pool.malloc());
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i;
        printf("Test: %d \n", arr[i]);
    }

    std::cout << std::format("Test memory  chunk is from int_pool: {} \n", (int_pool.is_from((void *)buf)))
              << std::endl;

    // object_pool
    // First use raw malloc() to allocate memory, second use constructor.
    printf(ANSI_FMT("Test for object pool \n", ANSI_BLUE));
    boost::object_pool<Demo> demo_pool;
    auto                     demo_ptr = demo_pool.malloc();

    std::cout << std::format(
                     ANSI_FMT("Malloced memory block size: {}, Is init class members: {} , string {} ", ANSI_BLUE),
                     demo_pool.is_from(demo_ptr), demo_ptr->m_a, demo_ptr->m_str
                 )
              << std::endl;

    demo_ptr = demo_pool.construct(10, 20, 30);
    std::cout << std::format(
                     "After constructor: {}, string \"{}\";\nSize of class Demo: {}", demo_ptr->m_a, demo_ptr->m_str,
                     sizeof(Demo)
                 )
              << std::endl;

    // Singleton pool
    printf(ANSI_FMT("Test for singleton_pool, it's \"pool\" singleton version \n", ANSI_BLUE));

    using int_spl = boost::singleton_pool<struct pool_tag, sizeof(int)>;

    auto ptr      = static_cast<int *>(int_spl::malloc());

    std::cout << std::format(ANSI_FMT("Singleton memory block: {}", ANSI_BLUE), int_spl::is_from(ptr)) << std::endl;
    int_spl::release_memory();

    return 0;
}
