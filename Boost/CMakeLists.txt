cmake_minimum_required(VERSION 3.20)
project(Boost)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Compiler setting
set(CMAKE_C_FLAGS "-g -ggdb -o0 -Wall" )
set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} )

set(CMAKE_EXE_LINKER_FLAGS "-v")

set(SRCS  timer.cpp
pool.cpp
noncopyable.cpp 
regex.cpp
filesystem.cpp
)


include_directories(
    .
    include 
)


# link boost library
find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(timer timer.cpp)
target_compile_definitions(timer PUBLIC  BOOST_TIMER_ENABLE_DEPRECATED )

add_executable(pool pool.cpp)
add_executable(noncopyable noncopyable.cpp)
add_executable(regex regex.cpp)

add_executable(filesystem filesystem.cpp)
target_link_libraries(filesystem Boost::system Boost::filesystem )