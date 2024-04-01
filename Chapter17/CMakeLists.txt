cmake_minimum_required(VERSION 3.27)
project(Chapter15)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chapter15 main.cpp)
add_executable(Ranges
        RangesCPP20/range.cpp)
