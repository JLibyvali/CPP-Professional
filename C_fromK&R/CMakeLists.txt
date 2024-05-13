cmake_minimum_required(VERSION 3.28)
project(C_fromK_R C)

set(CMAKE_C_STANDARD 11)

add_executable(C_fromK_R main.c
        Prac2.h
        Prac5.h
)

target_compile_definitions(C_fromK_R PRIVATE ARGUMENTS="2 3 4 + -")

target_link_libraries(C_fromK_R m)