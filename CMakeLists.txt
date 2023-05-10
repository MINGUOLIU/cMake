cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

project(
    VERSION 0.0.0
    DESCRIPION  "MINGUOLIU CMake demo"
    PROJECT_HOMEPAGE_URL "https://github.com/MINGUOLIU/cMake.git"
    LANGUAGE C CXX
)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(BulidInfo)

add_subdirectory(src)

