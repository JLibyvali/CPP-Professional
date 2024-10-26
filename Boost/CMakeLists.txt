cmake_minimum_required(VERSION 3.20)
project(Boost)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Compiler setting
set(CMAKE_C_FLAGS "-g -ggdb -o0 -Wall" )
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} )

set(SRCS  timer.cpp)
include_directories(
    .
    include 
)

add_executable(timer timer.cpp)
target_compile_definitions(timer PUBLIC  BOOST_TIMER_ENABLE_DEPRECATED )
