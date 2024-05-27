cmake_minimum_required(VERSION 3.27)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

set(LISTDIR LinkedList)
set(QandSDIR QandS)

include_directories(${CMAKE_SOURCE_DIR}/${LISTDIR}
                    ${CMAKE_CURRENT_LIST_DIR}/${QandSDIR})

file(GLOB QSSRC "${CMAKE_CURRENT_LIST_DIR}/${QandSDIR}/*.cpp")
file(GLOB LSRC "${CMAKE_SOURCE_DIR}/${LISTDIR}/*.cpp")

# DoublyList or SingalList
add_compile_definitions(LIST2)

add_executable(List main.cpp func.cpp ${QSSRC} ${LSRC})
