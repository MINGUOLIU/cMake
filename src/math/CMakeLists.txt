cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

cmake_policy(SET CMP0069 NEW)
cmake_policy(SET CMP0063 NEW)

add_library(math1 math.cpp)

target_include_directories(math1
    PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}
)