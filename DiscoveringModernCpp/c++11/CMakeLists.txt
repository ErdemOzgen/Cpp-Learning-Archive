file (GLOB SOURCES "./*.cpp")

# Skip sources with errors or needing other libraries, sources with warnings kept
file (GLOB SKIPPING "./empty.cpp" "./occi*.cpp" "./variadic_sum_left.cpp" "./instance*.cpp" "./inverse.cpp" "./julia.cpp"
                    "./adl_mult.cpp" "./enable_if_example.cpp" "./trans_const.cpp" "./mandelbrot.cpp" "./derivative.cpp"
					"./boost_*.cpp" "./vector_any.cpp" "./fsize_unroll_example.cpp" "./unary_plus_test.cpp")


strip_sources("${SOURCES}" "${SKIPPING}" COMPILE_SOURCES)
# message(STATUS "Sources to be compiled in c++03: ${COMPILE_SOURCES}")

add_standard_flag("c++11")

compile_all("false" "cpp11" "${COMPILE_SOURCES}")

add_library(instance_lib STATIC instance2.cpp)
add_executable(cpp11_instance instance1.cpp)
target_link_libraries(cpp11_instance instance_lib)
