cmake_minimum_required(VERSION 3.14)
project(vector_example)

set(CMAKE_CXX_STANDARD 14)

add_executable(test1 test1.cpp vector.cpp vector.h)
add_executable(test2 test2.cpp vector.cpp vector.h)
add_executable(test3 test3.cpp vector.cpp vector.h)
add_executable(test4 test4.cpp vector.cpp vector.h container.h vector_container.h vector_container.cpp list_container.cpp list_container.h)
add_executable(test5 test5.cpp vector.cpp vector.h)

