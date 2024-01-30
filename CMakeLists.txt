cmake_minimum_required(VERSION 3.19)
project(filter_lib VERSION 0.1.0 LANGUAGES CXX)

option(FILTERLIB_ENABLE_TESTS "Enable unit tests" ON)

set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD 20)

# speed up fetchcontent on consecutive runs
set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
add_subdirectory(ext)
add_subdirectory(impl)

if (FILTERLIB_ENABLE_TESTS)
    add_subdirectory(test)
endif ()

## copy .clang-format to build directory
#####################################################
configure_file(${CMAKE_SOURCE_DIR}/.clang-format ${CMAKE_BINARY_DIR}/ COPYONLY)
