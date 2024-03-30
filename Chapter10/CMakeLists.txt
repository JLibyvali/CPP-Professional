cmake_minimum_required(VERSION 3.27)
project(Chapter10)

set(CMAKE_CXX_STANDARD 20)
include_directories(${CMAKE_SOURCE_DIR}/Inherit)
include_directories(${CMAKE_SOURCE_DIR}/Polymorphism)



add_executable(Chapter10 main.cpp
        Polymorphism/StringSpreadCell.cpp
        Polymorphism/DoubleSpreadsheet.cpp
)