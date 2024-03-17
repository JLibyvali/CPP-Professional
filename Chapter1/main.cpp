#include <iostream>
#include <format>
#include "MARCO.h"
#include "InitialList.h"
#include "Employee.h"

#define  REF1  5
#include "Reference.h"

int main(){

    std::cout<<"***************MARCO***********************\n";
    Marco::Function1();

    std::cout<<"*****************Reference*****************************"<<std::endl;

#if REF1 ==0
    int unSplit[] = {1,2,3,4,5,6,7,8,9,10};
    int* oddsNums {nullptr};
    int* evensNums  {nullptr};
    size_t  numOdds{0}, numEvens{0};
    // void Separate(const int arr[], size_t size , int** odds, size_t* numOdds, int** evens, size_t* numEvens);
    Ref::Separate(unSplit,std::size(unSplit),&oddsNums,&numOdds,&evensNums,&numEvens);

    delete[] oddsNums; oddsNums=nullptr;
    delete[] evenNums; evensNums=nullptr;
    return 0;
#elif  REF1==1

    int unSplit[] = {1,2,3,4,5,6,7,8,9,10};
    int* oddsNums {nullptr};
    int* evensNums  {nullptr};
    size_t  numOdds{0}, numEvens{0};
    Ref::Separate(unSplit,std::size(unSplit),oddsNums,numOdds,evensNums,numEvens);

    delete[] oddsNums;oddsNums= nullptr;
    delete[] evensNums; evensNums = nullptr;
    return  0;
#elif  REF1==2
    std::vector<int>  unSplit  {1,2,3,4,5,6,7,8,9,10};
    auto result {Ref::Separate(unSplit)};

    // Output
    for (const auto& ele:result.odds) {
        std::cout<<std::format("The odds:{} ",ele);
    }
    std::cout<<std::endl;
    for (const auto& ele:result.evens) {
        std::cout<<std::format("The evens:{} ",ele);
    }


    return 0;

#else
    std::cout<<"Skip Reference!"<<std::endl;

#endif

    std::cout<<"#########################InitialList##################"<<std::endl;
    InitialList::MagicFoo arr {1,2,35,6,7,37,};

    std::cout<<"arr :";
    for (const auto& ele:arr.vec) {
        std::cout<<std::format(" {} ",ele);
    }

    std::cout<<"#########################Employee######################"<<std::endl;

};