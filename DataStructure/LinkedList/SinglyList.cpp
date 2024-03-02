//
// Created by jlibyvali on 24-3-2.
//

#include <iostream>
#include <array>
#include <chrono>

class Node{

private:
    int key;
    int data;
    Node* next;
public:

    Node(){
        key =0;
        data=0;
        next = nullptr;
    }
    Node(int _data){
        data = _data;

    }
};