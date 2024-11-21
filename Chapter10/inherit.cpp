#include "debug.h"

#include <curses.h>
#include <format>
#include <iostream>

class Base
{
public:

    Base() { std::cout << FMT("Base class Ctor", RED) << std::endl; }

    virtual ~Base() { std::cout << FMT("Base class dtor", BLACK) << std::endl; }

    virtual void info() { std::cout << "Infomation from Base" << std::endl; }

private:

    char m_c;
};

class Derived : public Base
{
public:

    Derived() { std::cout << FMT("Derived class ctor", BLUE) << std::endl; }

    ~Derived() { std::cout << FMT("Derived class dtor", BLACK) << std::endl; }

    void         info() override { std::cout << "Information from Derived" << std::endl; }

    virtual void go() { std::cout << "Derived go" << std::endl; }

private:

    char m_c;
};

int main()
{
    // Test the inherit and polymorphism
    std::cout << "Virtual size: Base class bytes: " << sizeof(Base) << " Derived class bytes: " << sizeof(Derived)
              << std::endl;

    std::cout << "Polymorphism: " << std::endl;

    std::cout << "But if no `virtual dtor`, delete will be sliced" << std::endl;
    Base *base_ptr{new Derived()};
    delete base_ptr;

    std::cout << "Stack variable can be free normally" << std::endl;
    // Derived _derived;

    // Test Upcasting and Downcasting
    std::cout << "Test Upcasting and Downcasting" << std::endl;
    Base base{Derived()};  // Slicing
    // No base.go(), Case this sliced casting, 

    return 0;
}