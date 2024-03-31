cmake_minimum_required(VERSION 3.27)
project(Chapter13)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_SOURCE_DIR}/Stream)

add_executable(FileStream Stream/Filestream.cpp)
add_executable(StreamLinker Stream/StreamLink.cpp)
add_executable(Chapter13 main.cpp)
