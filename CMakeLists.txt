cmake_minimum_required(VERSION 3.17)
project(bod2d)

set(CMAKE_CXX_STANDARD 14)

add_executable(bod2d main.cpp  hlava.h inout.h bod.cpp)