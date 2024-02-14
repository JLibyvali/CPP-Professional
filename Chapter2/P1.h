//
// Created by jlibyvali on 24-1-12.
//

#ifndef CHAPTER2_P1_H
#define CHAPTER2_P1_H

#include <iostream>
#include <format>
#include <string>
#include <string_view>
#include <array>
#include <vector>



namespace  P1{
#if TAG==0
    void Func1(); //Input two string,Output one string as word order.
    void sortString( std::array<std::string,2>& in);
#endif
}
#if  TAG==0
void P1::Func1(){

    std::array<std::string,2> inputString {};

    std::cout<<"Please input string 1\n:";
    getline(std::cin,inputString[0]);
    std::cout<<"Please input string 2\n:";
    getline(std::cin,inputString[1]);

    P1::sortString(inputString);

    return ;
}

void   P1::sortString(std::array<std::string, 2> &in) {

       std::string str {in[0] + in[1]};

      // const string& to ASCII num;
      std::vector<int> ascii {};

      for (const auto& ele:str) {
          ascii.push_back(static_cast<int>(ele));

      }

     // bubble sort
    for (int i = 0; i < ascii.size()-1 ; ++i) {
        for (int j = 0; j < ascii.size() - i - 1; ++j) {

            if (ascii[j] > ascii[j + 1]) std::swap(ascii[j], ascii[j + 1]);
        }
    }

    // ASCII num  to char and output.
    std::cout<<"The sort result:"<<std::endl;
    for (const auto& ele:ascii) {
        std::cout<<static_cast<char>(ele);
    }
    std::cout<<std::endl;
}

#endif



#endif //CHAPTER2_P1_H
