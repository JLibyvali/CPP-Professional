cmake_minimum_required(VERSION 3.20)
project(Iterator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Compiler setting
set(CMAKE_C_FLAGS "-g -ggdb -o0 -Wall" )
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} )

add_executable(vecotr vector.cpp)
