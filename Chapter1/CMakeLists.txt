cmake_minimum_required(VERSION 3.27)
project(Chapter1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Chapter1 main.cpp
        MARCO.h
        Reference.h
        Employee.h
        Employee.cpp
        InitialList.h)
