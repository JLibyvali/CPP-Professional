cmake_minimum_required(VERSION 3.27)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

#add_executable(DataStructure main.cpp)
add_executable(LinkedList
        #LinkedList/SinglyList.c
        LinkedList/Contact.cpp
        LinkedList/Contact.h
        LinkedList/DoublyList.c
)
