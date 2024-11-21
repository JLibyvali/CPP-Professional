#include "debug.h"

#include <cstddef>
#include <iostream>

class Base_O
{
public:
};

class Base
{
public:

    virtual void go() { std::cout << "Base class go()" << std::endl; }

    int          m_base = 10;
};

class Derived : public Base
{
public:

    void        go() override { std::cout << "Derived class go()" << std::endl; }

    static char m_c;
    int         m_base = 3;
};

char Derived::m_c = 'A';

int  main()
{
    // static_cast
    // static_cast can execute basic value cast, inheritance class cast need related ctor, but none type safety check.

    std::cout << "Test static_cast<>()" << std::endl;
    Base    *base_ptr{nullptr};
    Derived *derived_ptr{new Derived()};
    // base_ptr->go();    segmentation fault

    base_ptr = derived_ptr;  // Upcasting compiler will automatic  finished
    base_ptr->go();
    std::cout << "MEMBER: " << base_ptr->m_base << std::endl;

    derived_ptr = static_cast<Derived *>(base_ptr);  // Downcasting, work fine but none type safety
    derived_ptr->go();
    std::cout << "MEMBER: " << derived_ptr->m_base << std::endl;

    // It's static_cast none type safety:
    Base    *B_ptr{new Base()};
    Derived *D_ptr = static_cast<Derived *>(B_ptr);  // trigger some memory cover
    std::cout << "MEMBER Base class: " << B_ptr->m_base << " MEMBER derived class: " << D_ptr->m_base << std::endl;

    // static_cast cannot cast none inheritance ctor class
    // Base_O *bo_ptr = static_cast<Base_O*>(derived_ptr);

    // But  reinterpret_cast allow none relative ctor cast, usually used to convert to void*
    std::cout << FMT("Test reinterpret_cast<>()", RED) << std::endl;
    void *gen_ptr = (derived_ptr);
    auto  res_ptr = reinterpret_cast<Derived *>(gen_ptr);
    std::cout << "Reinterpret_cast: " << res_ptr->m_base << ", " << res_ptr->m_c << std::endl;

    std::cout << FMT("Test dynamic_cast<>()", RED) << std::endl;

    // dynamic_cast safety
    Base     base;
    Derived  derived;
    Base    &br{derived};  // Upcasting, normally

    // un allowed cast will throw exception.
    Derived &dr = static_cast<Derived &>(br);
    std::cout << "Static cast : " << dr.m_base << std::endl;

    Derived &dr_2 = dynamic_cast<Derived &>(br);

    return 0;
}