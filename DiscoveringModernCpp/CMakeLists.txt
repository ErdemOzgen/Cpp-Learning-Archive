project (dmc2)

cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0054 NEW)

option(DMC2_CMAKE_TRACE "Tracing CMake results, i.e. printing variable settings." OFF)
# option(DMC2_ENABLE_TESTS "Enable the build and run of tests." ON)
# option(DMC2_VERBOSE_TESTS "Always print test output, otherwise only errors. Only relevant when tests enabled." OFF)
option(DMC2_ENABLE_CPP20 "Enable compilation of C++20 examples." OFF)

# extra libs
option(DMC2_ENABLE_NIEBLER "Enable usage of Eric Niebler's range implementation" OFF)
option(DMC2_ENABLE_FMT "Enable usage of external fmt library" OFF)

macro(trace_variable variable)
    if (DMC2_CMAKE_TRACE)
        message(STATUS "${variable} = ${${variable}}")
    endif()
endmacro()

find_package (Threads)

# Cannot call it DMC2_DIR since this is implicitly used by the find package.
set(DMC2_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
trace_variable(DMC2_ROOT)

  
# Must be located in root dir, doesn't work in tests
# if (DMC2_ENABLE_TESTS)
#     enable_testing()
#     # include(Dart)
# endif()

### remove every file in skipping from sources
function(strip_sources sources skipping result)
  set(sources_local ${sources})
  foreach(skip ${skipping})
    list(REMOVE_ITEM sources ${skip})
  endforeach()
  set(${result} "${sources}" PARENT_SCOPE)
endfunction()

function(standard_flag standard result)
  if (standard STREQUAL "c++03")    
    set(${result} "" PARENT_SCOPE)
  elseif(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")  
    set(${result} "-std=${standard}" PARENT_SCOPE)
  elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    if (standard STREQUAL "c++11")
      set(${result} "" PARENT_SCOPE) # no flag for C++11
    elseif (standard STREQUAL "c++14")
      set(${result} "/std:c++14" PARENT_SCOPE)
    elseif (standard STREQUAL "c++17")
      set(${result} "/std:c++latest" PARENT_SCOPE) # might change some day
    elseif (standard STREQUAL "c++2a" OR standard STREQUAL "c++20")
      set(${result} "/std:c++latest" PARENT_SCOPE) # might change some day
    else()
      message(FATAL_ERROR "Unknown standard")
    endif()
  else()
    message(FATAL_ERROR "Compiler not supported")
  endif()  
endfunction()

macro(add_standard_flag standard)
  standard_flag(${standard} FLAG)
  add_definitions(${FLAG})
endmacro()

macro(add_thread_support)
  if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_definitions(-pthread)
  endif()
endmacro()

### compiles all source files passed in, adds test if testing is true, prepends prefix to target
macro (compile_all testing prefix)
    # cycle through the sources and create an executable for it
    foreach (source ${ARGN})
        get_filename_component (test ${source} NAME_WE)
        string(REPLACE " " ";" new_source ${source})
        set(test_name ${prefix}_${test})
        # message(STATUS "Add test ${test_name} from source ${new_source}.")
        add_executable (${test_name} ${new_source})
	target_link_libraries (${test_name} ${CMAKE_THREAD_LIBS_INIT}) # some examples need thread support
        if (${testing} STREQUAL "true")
            if (DMC2_CMAKE_TRACE)
                message(STATUS "testing: ${test_name} ${RUNTIME_OUTPUT_DIRECTORY}/${test_name}")
            endif()
            add_test(${test_name} ${RUNTIME_OUTPUT_DIRECTORY}/${test_name})
        endif()
    endforeach (source)
endmacro (compile_all)

message(STATUS "The Compiler is ${CMAKE_CXX_COMPILER} and its Id ${CMAKE_CXX_COMPILER_ID}.")

add_subdirectory(c++03)
add_subdirectory(c++11)
add_subdirectory(c++14)
add_subdirectory(c++17)

if (DMC2_ENABLE_CPP20)
    message(STATUS "Compiling C++20")
    add_subdirectory(c++20)
endif()

# stumbles sometimes on Windows
if (NOT CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_subdirectory(CMake_example)
endif()

# Maybe compile and test ode_solver at some point

