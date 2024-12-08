module;
#include <iostream>

export module Hello:other;

export void   World() { std::cout << "World!!!" << std::endl; }