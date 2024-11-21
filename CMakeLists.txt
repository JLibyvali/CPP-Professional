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
add_executable ( diamond_inheritace Chapter10/multi_inherit.cpp )
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
add_executable(vecotr_perf Chapter18/vector_test.cpp Chapter18/vector_perf.h)
add_executable(vecotr_size Chapter18/vecotr_size.cpp Chapter18/vector_perf.h)
