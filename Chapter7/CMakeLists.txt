cmake_minimum_required(VERSION 3.27)
project(Memory)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pointer
        pointer/main.cpp)
add_executable(uniquePointer uniquePointer/demo.cpp)
