cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_subdirectory(math)

cmake_policy(SET CMP0063 NEW)
cmake_policy(SET CMP0069 NEW)

add_executable(test cmake.cpp)
add_executable(cmake cmake.cpp)

target_link_libraries(cmake
    PUBLIC
        math1
)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(math1
    PUBLIC
    math1
)