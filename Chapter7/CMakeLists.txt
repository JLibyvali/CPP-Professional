cmake_minimum_required(VERSION 3.20)
project(Memory)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Compiler setting
set(CMAKE_C_FLAGS "-g -ggdb -o0 -Wall" )
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} )

set(SRCS 
raw_pointer.cpp 
size.cpp
smart_pointer.cpp 
weak_ptr.cpp)


add_executable(size class_size.cpp)
add_executable(raw raw_pointer.cpp)
add_executable(smart_ptr smart_pointer.cpp)
add_executable(weak_ptr weak_ptr.cpp)
