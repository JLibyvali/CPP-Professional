cmake_minimum_required ( VERSION 3.28 )
project ( CPP_pro )

set ( CMAKE_CXX_STANDARD 20 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS OFF )
set ( CMAKE_C_FLAGS_DEBUG "-g3 -ggdb3 -O0 -Wall" )
set ( CMAKE_CXX_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG} )

include_directories (
    .
    include
)

# CPP Modules
# Requirements: CMake Version >= 3.28, Header Unit still not support, std library need module encapsulates
# Clang Version >= 16.0, GCC Version >= 14
# Header Module Unit need Clang >= 18.0
add_library ( Hello )
target_sources ( Hello PUBLIC FILE_SET hellomod_srcs TYPE CXX_MODULES FILES
    Module/Hello.cppm
    Module/hello_other.cppm
)
target_sources ( Hello PUBLIC Module/hello_impl.cpp )

add_library ( Sort )
target_sources ( Sort PUBLIC FILE_SET sortmod_srcs TYPE CXX_MODULES FILES
    Module/Sort.cppm
    Module/Sort_interface.cppm
    Module/Sort_implpart.cppm
)
target_sources ( Sort PUBLIC Module/Sort_impl.cpp )

add_executable ( HelloSort Module/User.cpp )
target_link_libraries ( HelloSort PRIVATE Hello Sort )

# boost
# add_subdirectory(Boost)

# class size and smart pointer
add_executable ( class_size Chapter7/class_size.cpp )
add_executable ( raw_pointer Chapter7/raw_pointer.cpp )
add_executable ( smart_ptr Chapter7/smart_pointer.cpp )
add_executable ( weak_ptr Chapter7/weak_ptr.cpp )

# 5 rules
add_executable ( 5rules_constructor Chapter8_9/5rules.cpp )

# OOP  inherit
add_executable ( basic_inheritance Chapter10/inherit.cpp )
add_executable ( diamond_inheritace Chapter10/diamond_inheritance.cpp )
add_executable ( override_load Chapter10/override_load.cpp )
add_executable ( type_cast Chapter10/cast.cpp )

# Multi-treads, atomic programming
add_executable ( basic_threads Chapter27/basic_thread.cpp )
add_executable ( atomic Chapter27/atomic.cpp )
add_executable ( lock Chapter27/lock.cpp )
add_executable ( condition_variable Chapter27/condition_var.cpp )
add_executable ( latch_barrier Chapter27/latch.cpp )
add_executable ( semaphore Chapter27/semaphore.cpp )
target_link_libraries ( atomic PUBLIC -latomic )

# Container related
add_executable ( vecotr_perf Chapter18/vector_test.cpp Chapter18/vector_perf.h )
add_executable ( vecotr_size Chapter18/vecotr_size.cpp Chapter18/vector_perf.h )
