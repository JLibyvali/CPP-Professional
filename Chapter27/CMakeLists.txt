cmake_minimum_required(VERSION 3.20)
project(Iterator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


include_directories(../include )

# Compiler setting
set(CMAKE_C_FLAGS "-g -ggdb -o0 -Wall" )
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} )
set(CMAKE_EXE_LINKER_FLAGS "-pg")


add_executable(basic basic_thread.cpp)
add_executable(atomic atomic.cpp)
target_link_libraries(atomic PUBLIC -latomic)

add_executable(lock lock.cpp)
add_executable(cond condition_var.cpp)
add_executable(latch latch.cpp)
add_executable(semaphore semaphore.cpp)