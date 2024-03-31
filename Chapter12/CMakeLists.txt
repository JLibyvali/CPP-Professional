cmake_minimum_required(VERSION 3.27)
project(Chapter12)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/Base)
include_directories(${CMAKE_SOURCE_DIR}/Template)
include_directories(${CMAKE_SOURCE_DIR}/Conception)

add_executable(Chapter12 main.cpp)
