cmake_minimum_required(VERSION 3.27)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

set(LISTDIR   LinkedList)
set(STACKDIR  Stacks)
set(QUEDIR  Queue)

include_directories(${CMAKE_SOURCE_DIR}/${LISTDIR})

add_executable(List
  main.cpp
  LinkedList/DoublyList.cpp
)
