cmake_minimum_required(VERSION 3.27)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

include_directories(${CMAKE_CURRENT_LIST_DIR}/${LISTDIR}
                    ${CMAKE_CURRENT_LIST_DIR}/${QandSDIR}
                    ${CMAKE_CURRENT_LIST_DIR}/${TREEDIR})

file(GLOB QSSRC "${CMAKE_CURRENT_LIST_DIR}/${QandSDIR}/*.cpp")
file(GLOB LSRC "${CMAKE_SOURCE_DIR}/${LISTDIR}/*.cpp")
file(GLOB TSRC "${CMAKE_CURRENT_LIST_DIR}/${TREEDIR}/*.cpp")

# DoublyList or SingalList
add_compile_definitions(LIST2)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
