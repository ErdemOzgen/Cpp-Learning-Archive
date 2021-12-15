file (GLOB SOURCES "./*.cpp")

# Skip sources with errors or needing other libraries, sources with warnings kept
file (GLOB SKIPPING "./*mpi_*.cpp" "./glas_*.cpp" "./build_example.ii.cpp" "./empty.cpp"
                    "./inverse.cpp" "./interoperable.cpp" "./static_main.cpp" "./static_f.cpp" "./cg_nice.cpp"
		            "./unruh.cpp" "./enable_if_test.cpp" "./const_view_test.cpp" "./magnitude_test.cpp"
		            "./occi*.cpp" "./release_98_test.cpp" "./bool_stuff.cpp" 
			        "./*_unroll*.cpp" "./vector_expression_test.cpp" "./mc_integration.cpp")
		  
# message(STATUS "All sources in c++03: ${SOURCES}")
# message(STATUS "Sources to be skipped in c++03: ${SKIPPING}")

strip_sources("${SOURCES}" "${SKIPPING}" COMPILE_SOURCES)
# message(STATUS "Sources to be compiled in c++03: ${COMPILE_SOURCES}")

compile_all("false" "cpp03" "${COMPILE_SOURCES}")

# TODO: portable version for interoperable and static_main

add_library(static_f_lib STATIC static_f.cpp)
add_executable(cpp03_static_main static_main.cpp)
target_link_libraries(cpp03_static_main static_f_lib)

add_library(interoperable_lib STATIC interoperable.cpp)
add_executable(cpp03_interoperable_main interoperable_main.c)
target_link_libraries(cpp03_interoperable_main interoperable_lib)
