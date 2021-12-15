file (GLOB SOURCES "./*.cpp")

# Skip sources with errors or needing other libraries, sources with warnings kept
file (GLOB SKIPPING "./empty.cpp" "./const_view_template_variables.cpp" "./init_capture.cpp" "./value_range_vector.cpp")

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	# trouble with specializing variables
	file (GLOB EXTRASKIPPING  "./modern_derivative*.cpp")
	set(SKIPPING "${SKIPPING};${EXTRASKIPPING}")
endif()

strip_sources("${SOURCES}" "${SKIPPING}" COMPILE_SOURCES)
# message(STATUS "Sources to be compiled in c++14: ${COMPILE_SOURCES}")

add_standard_flag("c++14")

compile_all("false" "cpp14" "${COMPILE_SOURCES}")

