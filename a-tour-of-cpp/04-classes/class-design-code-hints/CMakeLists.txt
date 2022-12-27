cmake_minimum_required(VERSION 3.14)
project(class_design_code_hints)

set(CMAKE_CXX_STANDARD 14)

add_executable(1-const-member-functions 1-const-member-functions.cpp)
add_executable(2-problem-when-returning-handles-to-object-internals 2-problem-when-returning-handles-to-object-internals.cpp)
add_executable(3-solution-to-return-handles-to-object-internals 3-solution-to-return-handles-to-object-internals.cpp)
add_executable(4-const-overloading-operators-problem1 4-const-overloading-operators-problem1.cpp)
add_executable(5-const-overloading-operators-problem2 5-const-overloading-operators-problem2.cpp)
add_executable(6-const-overloading-operators-problem3 6-const-overloading-operators-problem3.cpp)
add_executable(7-const-overloading-operators-problem4 7-const-overloading-operators-problem4.cpp)
add_executable(8-const-overloading-operators-solution1 8-const-overloading-operators-solution1.cpp)