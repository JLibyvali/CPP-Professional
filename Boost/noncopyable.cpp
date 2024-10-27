#include "debug.h"

#include <boost/core/noncopyable.hpp>
#include <boost/noncopyable.hpp>
#include <cstdio>
#include <format>
#include <iostream>

class RAII : boost::noncopyable
{
public:

    RAII() { printf(ANSI_FMT("Ctor of non copy class \n", ANSI_BLUE)); }

    std::string str = "Hello world \n";
};

int main()
{
    RAII r1;

    // Error case RAII is non  copyable 
    // RAII r2 {r1};
    // RAII r3 = r1;

    return 0;
}