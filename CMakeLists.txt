# cmake_minimum_required(VERSION 3.23 FATAL_ERROR)

# project(cmake
#     VERSION 0.0.0
#     DESCRIPION  "MINGUOLIU CMake demo"
#     PROJECT_HOMEPAGE_URL "https://github.com/MINGUOLIU/cMake.git"
#     LANGUAGE C CXX
# )


# list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# include(BulidInfo)

# add_subdirectory(external)

# add_subdirectory(src)

# add_subdirectory(docs)

# add_subdirectory(test)

#  add_subdirectory(packaging)

#############################################

cmake_minimum_required(VERSION 3.23 FATAL_ERROR)


project(test
    VERSION         0.0.1
    DESCRIPTION     "Eglinux's cmake study test repo"
    HOMEPAGE_URL    "公众号: eglinux"
    LANGUAGES       CXX
)

list(APPEND CMAKE_MESSAGE_CONTEXT       "test")
list(APPEND CMAKE_MODULE_PATH           "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS       ON)
set(TEST_TOP_SOURCE_DIR          ${CMAKE_CURRENT_SOURCE_DIR})
set(TEST_TOP_BINARY_DIR          ${CMAKE_CURRENT_BINARY_DIR})

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR
      "\n"
      "In-source builds are not allowed.\n"
      "Instead, provide a path to build tree like so:\n"
      "cmake -S . -B <destination>\n"
      "\n"
      "To remove files you accidentally created execute:\n"
      "please delete CMakeFiles and CMakeCache.txt\n"
    )
endif()

set(CMAKE_CXX_STANDARD              20 )
set(CMAKE_CXX_STANDARD_REQUIRED     ON )
set(CMAKE_CXX_EXTENSIONS            OFF)
# set(CMAKE_CXX_VISIBILITY_PRESET     hidden)
# set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)
set(CMAKE_INSTALL_RPATH             $ORIGIN $ORIGIN/../lib)
set(CMAKE_INSTALL_PREFIX            "/usr/local")

if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
    include(CheckIPOSupported)
    check_ipo_supported(RESULT ipo_supported)
    if(ipo_supported)
        message(STATUS "enable INTERPROCEDURAL OPTIMIZATION" )
        set(CMAKE_INTERPROCEDURAL_OPTIMIZATION True)
    endif()
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    message(STATUS "Configuring on/for Linux")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    message(STATUS "Configuring on/for macOS")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    message(STATUS "Configuring on/for Windows")
else()
    message(STATUS "Configuring on/for ${CMAKE_SYSTEM_NAME}")
endif()

include (TestBigEndian)
test_big_endian(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
    message(STATUS "Configuring on/for BIG_ENDIAN")
else()
    message(STATUS "Configuring on/for LITTLE_ENDIAN")
endif()

include(GNUInstallDirs)
include(GenerateExportHeader)

# include(BuildInfo)
# GenerateBuildInfo(${CMAKE_CURRENT_LIST_DIR}/test_build_info.h.in ${CMAKE_CURRENT_BINARY_DIR}/test_build_info.h)

# add_subdirectory(external)
add_subdirectory(src)

if(BUILD_TESTING AND PROJECT_IS_TOP_LEVEL)
    add_subdirectory(test)
endif()

# install(FILES ${CMAKE_CURRENT_BINARY_DIR}/test_build_info.h
#     DESTINATION
#         ${CMAKE_INSTALL_INCLUDEDIR}
# )

# add_subdirectory(packaging)



