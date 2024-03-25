cmake_minimum_required(VERSION 3.27)
project(CLASS)
set(CMAKE_CXX_STANDARD 20)


include_directories(${CMAKE_SOURCE_DIR}/PimplIdiom)

add_executable(INTERFACE
        main.cpp
        PimplIdiom/Spreadsheetcell.cpp
        PimplIdiom/Inplementation.cpp
)
