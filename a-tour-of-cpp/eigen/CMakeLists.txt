cmake_minimum_required(VERSION 3.14)
project(eigen)

set(CMAKE_CXX_STANDARD 14)

include_directories(eigen)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")


add_executable(eigen main.cpp)