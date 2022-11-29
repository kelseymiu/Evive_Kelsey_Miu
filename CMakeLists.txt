cmake_minimum_required(VERSION 3.20)
project(evive)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        MenuOrdering.cpp
        MenuOrdering.h)
add_executable(evive ${SOURCE_FILES})