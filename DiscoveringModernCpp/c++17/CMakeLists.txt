file (GLOB SOURCES "./*.cpp")

# Skip sources with errors or needing other libraries, sources with warnings kept
file (GLOB SKIPPING "./empty.cpp" "./filesystem_example.cpp")

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # at least with g++-9
	# needs TBB
	file (GLOB EXTRASKIPPING "./parallel_stl.cpp" "./parallel_sort.cpp" "./parallel_reduce.cpp")
	set(SKIPPING "${SKIPPING};${EXTRASKIPPING}")
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	# trouble with class type deduction, specializing template variables,
	file (GLOB EXTRASKIPPING  "./class_type_deduction*.cpp" "./modern_derivative*.cpp" "./constexpr_lambda.cpp")
	set(SKIPPING "${SKIPPING};${EXTRASKIPPING}")
endif()
# message(STATUS "Sources to be skipped in c++17: ${SKIPPING}")

strip_sources("${SOURCES}" "${SKIPPING}" COMPILE_SOURCES)
# message(STATUS "Sources to be compiled in c++17: ${COMPILE_SOURCES}")

add_standard_flag("c++17")

compile_all("false" "cpp17" "${COMPILE_SOURCES}")


# evil hack needed as long as filesystem is not ready yet
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_executable(cpp17_filesystem_example filesystem_example.cpp)
  target_link_libraries(cpp17_filesystem_example stdc++fs)
endif()

# both libs don't work (for me)
# if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#   add_executable(cpp17_filesystem_example filesystem_example.cpp)
#   target_link_libraries(cpp17_filesystem_example c++fs)
#   target_link_libraries(cpp17_filesystem_example c++experimental)
# endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  add_executable(cpp17_filesystem_example filesystem_example.cpp)
endif()
