cmake_minimum_required(VERSION 3.14)
project(3_compiling_templates_sol3)

set(CMAKE_CXX_STANDARD 14)

# We removed the compilation of vector.cpp, since it is included in vector.h
# Thus, we do not have problems of function redefinition.
add_executable(2_compiling_templates_sol2 main.cpp vector.h)
