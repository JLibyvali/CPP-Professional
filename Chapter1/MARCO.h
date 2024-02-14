//
// Created by jlibyvali on 24-1-9.
//

#ifndef CHAPTER1_MARCO_H
#define CHAPTER1_MARCO_H

#include <iostream>
#include <format>

namespace Marco{

#define WAY 200

    void Function1();
}

inline void Marco::Function1(){

    std::cout << std::format("Test for `format`,There exit {} ways to Love.", WAY) << std::endl;
    std::cout<<"This is Next \n";
    std::cout<<"Line"<<std::endl;
}


#endif //CHAPTER1_MARCO_H