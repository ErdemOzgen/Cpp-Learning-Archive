cmake_minimum_required (VERSION 2.6)
project (Fluxer)
cmake_policy(SET CMP0054 NEW)

# mesher didn't work as lib name for VS 
add_library(mesherlib SHARED mesher.cpp)

add_library(solver solver.cpp)

add_executable(fluxer fluxer.cpp)
target_link_libraries(fluxer solver mesherlib)