# message(STATUS "Compiling C++20 directory.")

file (GLOB SOURCES "./*.cpp")

# Skip sources with errors or needing other libraries, sources with warnings kept
file (GLOB SKIPPING "./format_example.cpp" "./vector_formatted_output.cpp")

strip_sources("${SOURCES}" "${SKIPPING}" COMPILE_SOURCES)

add_standard_flag("c++2a")
# add_standard_flag("c++20")

if (DMC2_ENABLE_NIEBLER)
    set(DMC2_NIEBLER_INCLUDE_DIR "" CACHE PATH
        "The include directory for Eric Niebler's range library")
    message (STATUS "The include directory for Eric Niebler's range library is ${DMC2_NIEBLER_INCLUDE_DIR}.")
    add_definitions("-DDMC2_WITH_NIEBLER")
    include_directories(${DMC2_NIEBLER_INCLUDE_DIR})
endif()

if (DMC2_ENABLE_FMT)
    set(DMC2_FMT_INCLUDE_DIR "" CACHE PATH "The include directory for the format library")
    set(DMC2_FMT_LIB "" CACHE PATH "The directory for the compiled format library")
    message (STATUS "The include directory for the format library is ${DMC2_FMT_INCLUDE_DIR}.")
    message (STATUS "The directory for the compiled format library is ${DMC2_FMT_LIB}.")
    add_definitions("-DDMC2_WITH_FMT")
    include_directories(${DMC2_FMT_INCLUDE_DIR})
    link_directories(${DMC2_FMT_LIB})
    add_executable (cpp20_format_example format_example.cpp)
    target_link_libraries(cpp20_format_example fmt)
    add_executable (cpp20_vector_formatted_output vector_formatted_output.cpp)
    target_link_libraries(cpp20_vector_formatted_output fmt)    
endif()

compile_all("false" "cpp20" "${COMPILE_SOURCES}")

