//
// Created by jlibyvali on 24-1-10.
//

#ifndef CHAPTER1_REFERENCE_H
#define CHAPTER1_REFERENCE_H

#include <iostream>
#include <format>
#include <vector>


namespace Ref {
#if REF1==0

    void Separate(const int arr[], size_t size , int** odds, size_t* numOdds, int** evens, size_t* numEvens);

#elif REF1==1
    void Separate(const int arr[], size_t size, int *&odds, size_t &numOdds, int *&evens, size_t &numEvens);
#else
    struct  Result{ std::vector<int> odds,evens; };
    Result Separate(const std::vector<int>& arr);
#endif
}// Ref


#if REF1==0

inline  void  Ref::Separate(const int arr[], size_t size , int** odds, size_t* numOdds, int** evens, size_t* numEvens) {
    *numEvens = 0;
    *numOdds - 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) ++(*numOdds);
        else ++(*numOdds);
    }

    // Allocate two new arrays of the  appropriate size
    *odds = new int[*numOdds];
    *evens = new int[*numEvens];

    // Copy odds and evens  from arr[] to the new arrays.
    size_t oddsPos = 0, evensPos = 0;
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) (*odds)[oddsPos++] = arr[i];
        else (*evens)[evensPos++] = arr[i];

    }

    // Output
    std::cout<<std::format("There exist {} odds:",oddsPos);
    for (size_t i = 0; i < oddsPos; ++i) {
        std::cout<<std::format(" {} ",(*odds)[i]);
    }
    std::cout<<std::format("\nThere exist {} evens:",evensPos);
    for (int i = 0; i < evensPos; ++i) {
        std::cout<<std::format(" {} ",(*evens)[i]);
    }

}

#elif  REF1==1

inline void Ref::Separate(const int arr[],size_t size,int* &odds,size_t& numOdds,int* &evens,size_t& numEvens){
numOdds = numEvens =0;
for(size_t i=0;i<size;i++){
    if(arr[i] % 2 ==1) numOdds++;
    else numEvens++;
}
odds = new int[numOdds];
evens = new int[numEvens];

// Copy odds and evens from arr[] to new arrays.
size_t oddsPos = 0,evenPos=0;
for (size_t i = 0; i < size; ++i) {
    if (arr[i]%2==1) odds[oddsPos++] = arr[i];
    else evens[evenPos++] = arr[i];
}


// Output
std::cout<<std::format("There exist {} odds:",oddsPos);
for (int i = 0; i < oddsPos; ++i) {
        std::cout<<std::format(" {} ",odds[i]);
}
std::cout<<std::format("\nThere exis {} evens:",evenPos);
for (int i = 0; i < evenPos; ++i) {
        std::cout<<std::format(" {} ",evens[i]);
}

}

#else

  inline Ref::Result  Ref::Separate(const std::vector<int> &arr) {

      std::vector<int> odds,evens;
      for (const auto& ele:arr) {
          if ((ele%2)==1) odds.push_back(ele);
          else evens.push_back(ele);
      }
      return  Result{.odds = odds,
                     .evens=evens};
}

#endif

#endif //CHAPTER1_REFERENCE_H