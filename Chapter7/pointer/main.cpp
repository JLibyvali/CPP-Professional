//
// Created by jlibyvali on 24-3-17.
//


#include <iostream>
#include <format>

using namespace std;


int main() {

// First, "stack" or "heap"

    int arr1[]{1, 2, 3, 4, 5};
    int* ptr = arr1;
    int*  arr2 {new int[]{7,8,9,10,11}};

    for(int i=0;i<5;i++){
        cout<<format("Arr1 Value:{} ",arr1[i])<<"Memory["<<&arr1[i]<<"]"<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<format("Arr2 Value:{} ",arr2[i])<<"Memory["<<&arr2[i]<<"]"<<endl;
    }
//First, free memory
    delete[] arr2;
    arr2 = nullptr;




    return 0;
}