cmake_minimum_required(VERSION 3.6)   # CMake version check
project(lab4-assignment-moose32-master)
set(CMAKE_CXX_STANDARD 11)            # Enable c++11 standard
set(SOURCE_FILES Lab4.c)
add_executable(lab4 ${SOURCE_FILES})