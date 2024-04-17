cmake_minimum_required(VERSION 3.28)
project(Chapter18)

set(CMAKE_CXX_STANDARD 20)

add_executable(Container main.cpp
        Vector/RoundRobin.h
        Vector/Process.h
        Queue/PacketBuff.h
        Priority_queue/Error.h
        Associated/BankDB.h
        Associated/Buddy.h
        Bitset/CableCompany.h)
