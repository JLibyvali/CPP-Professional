#include <iostream>

class Base
{
public:

    Base(){}
    virtual void go() { std::cout << "Base class go()" << std::endl; }

    Base(const Base &src) {}
};

class Sub : public Base
{
public:

    Sub(){}
    // Overload Base class virtual method
    // void go() override { std::cout << "Derived class go()" << std::endl; }
    using Base::go;

    virtual void go(int i) { std::cout << "Derived class ID: " << i << std::endl; }

    // Derived class copy ctor have to bind base class copy ctor
    // If not will call Base class default ctor
    Sub(const Sub &src) : Base(src) {}
};

int main()
{

    // Test overload for virtual method
    Base *base_over = new Sub();
    Sub   sub;
    std::cout << "Test overload" << std::endl;
    base_over->go();
    sub.go(13);

    return 0;
}