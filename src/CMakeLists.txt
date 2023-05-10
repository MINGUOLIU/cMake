cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

#add_subdirectory(math)

cmake_policy(SET CMP0063 NEW)
cmake_policy(SET CMP0069 NEW)

add_executable(test cmake.cpp)
add_executable(cmake cmake.cpp)