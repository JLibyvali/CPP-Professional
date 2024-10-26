#include <iostream>

// Test for class size
class Empty_class   // 1 Byte
{};

class Normal_class  // 8 Bytes
{
public:

    void msg();

private:

    int *ptr = NULL;
};

void Normal_class::msg() { std::cout << "Normal class" << std::endl; }

class Virtual_class  // 16 Bytes case memory align

{
public:

    // Test class size
    virtual void msg(void);

    virtual void msg2() { std::cout << "message 2:" << std::endl; }

private:

    char c = 'a';
};

void Virtual_class::msg(void) { std::cout << "It's virtual message" << std::endl; }

class Int_class  // 8 Bytes case memory align
{
public:

    // const method return const value
    const int  get() const;

    // non-const method return const value;
    const char get_c();

private:

    char m_c    = 'a';
    int  m_data = 1;
};

const int  Int_class::get() const { return m_data; }

const char Int_class::get_c() { return m_c; }

int        main()
{

    const Int_class int_obj;
    Int_class       int_obj_nconst;
    Empty_class     empty_obj;
    Normal_class    normal_obj;
    Virtual_class   virt_obj;

    std::cout << "Int Class size:  " << sizeof(Int_class) << ".\tObject size: " << sizeof(int_obj) << std::endl;
    std::cout << "Normal Class size:  " << sizeof(Normal_class) << ".\tObject size: " << sizeof(normal_obj)
              << std::endl;
    std::cout << "Empty Class size:  " << sizeof(Empty_class) << ".\tObject size: " << sizeof(empty_obj) << std::endl;
    std::cout << "Virtual Class size:  " << sizeof(Virtual_class) << ".\tObject size: " << sizeof(virt_obj)
              << std::endl;

    return 0;
}