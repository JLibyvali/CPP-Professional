#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

#define ANSI_BLACK         "\33[1;30m"
#define ANSI_RED           "\33[1;31m"
#define ANSI_BLUE          "\33[1;34m"
#define ANSI_NONE          "\33[0m"

#define ANSI_FMT(str, fmt) fmt str ANSI_NONE

class Test
{
public:

    Test() : m_weight(-1), m_height(-1), m_arr(nullptr) { printf("CALL the Default ctor\n"); }

    Test(int w, int h) : m_weight(w), m_height(h)
    {
        std::cout << typeid(*this).name() << ": call the Delegation Ctor" << std::endl;
        m_arr = new char *[m_weight];

        for (int i = 0; i < m_weight; i++)
        {
            m_arr[i] = new char[m_height];
        }
    }

    virtual ~Test()
    {
        std::cout << typeid(*this).name() << ": call the Dtor..." << std::endl;
        for (int i = 0; i < m_weight; i++)
        {
            delete[] m_arr[i];
            m_arr[i] = nullptr;
        }
        delete[] m_arr;
        m_arr = nullptr;
    }

    // Copy to deeply copt
    // Copy not move, so after copy original object should be well.
    // So have to implement `copy ctor` to  allocate new memory,
    // Can use `copy and swap` for assignment operator.
    Test(const Test &src);
    Test &operator=(Test &rhs);

    // Move
    Test(Test &&src) noexcept;
    Test             &operator=(Test &&rhs) noexcept;

    const std::string getStr() const { return m_str; }

    void              setStr(const std::string &str)
    {
        printf("Lvalue version: \n");
        m_str = std::move(str);
    };

    void setStr(std::string &&str)
    {
        printf("Rvalue version: \n");
        m_str = str;
    }

private:

    friend void swap(Test &lhs, Test &rhs);

    // For safe and deep copy
    void        swap(Test &src) noexcept
    {
        std::swap(this->m_weight, src.m_weight);
        std::swap(this->m_height, src.m_height);
        std::swap(this->m_str, src.m_str);
        std::swap(this->m_arr, src.m_arr);
    }

    // For really move
    void movedFrom(Test &src) noexcept
    {
        // basic type data member;
        this->m_weight = std::exchange(src.m_weight, 0);
        this->m_height = std::exchange(src.m_height, 0);

        this->m_str    = std::move(src.m_str);
        this->m_arr    = std::exchange(src.m_arr, nullptr);
    }

    int         m_weight, m_height;
    std::string m_str;
    char      **m_arr;
};

// Declare a function more  convenient.
void swap(Test &lhs, Test &rhs) { lhs.swap(rhs); }

// ##############################################################
//  Using copy and swap for copy operations
// ###############################################################3
Test::Test(const Test &src) : m_weight(src.m_weight), m_height(src.m_height), m_str(src.m_str)
{

    printf(ANSI_FMT("Called the Copy Ctor.........\n", ANSI_RED));
    m_arr = new char *[m_weight];

    for (int i = 0; i < m_weight; i++)
    {
        m_arr[i] = new char[m_height];

        // Using STL copy
        std::copy(src.m_arr[i], src.m_arr[i] + m_height, m_arr[i]);
    }
}

Test &Test::operator=(Test &rhs)
{
    if (this == &rhs)
        return *this;

    printf(ANSI_FMT("Called the Copy =..........\n", ANSI_RED));
    Test tmp{rhs};

    swap(tmp);

    return *this;
}

// ########################################################3
//  Implement class move sematic
// #######################################################

Test::Test(Test &&src) noexcept
{
    printf(ANSI_FMT("Called the move Ctor...........\n", ANSI_BLUE));
    movedFrom(src);
}

Test &Test::operator=(Test &&src) noexcept
{
    if (this == &src)
        return *this;

    printf(ANSI_FMT("Called the move =...........\n", ANSI_BLUE));

    movedFrom(src);
    return *this;
}

void test(Test &_ts)
{
    printf("New function \n");
    std::cout << _ts.getStr() << std::endl;
}

int main()
{
    // Test for default ctor
    Test ts(10, 20);
    ts.setStr("Hello World, test for 5 rules");

    // test copy ctor and copy =
    Test test_copy;
    test_copy = ts;

    // Using `vector push_back()` test move operation
    std::vector<Test> vec;
    for (int i = 0; i < 2; i++)
    {
        printf("Iteration: %d \n", i);
        vec.push_back(Test{2, 2});  // Anonymous object for move
    }

    // Test After move,  original object memory live
    std::cout << test_copy.getStr() << std::endl;

    printf(ANSI_FMT("Test using std::move \n", ANSI_RED));
    vec.push_back(std::move(test_copy));
    std::cout << test_copy.getStr() << std::endl;  // Passed compiling, but no data.

    printf(ANSI_FMT("Test after moved original Object \n", ANSI_RED));

    // Copy sematic still work fine, but no data.
    test(test_copy);  // Passed compiling,

    return 0;
}