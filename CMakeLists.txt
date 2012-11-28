cmake_minimum_required(VERSION 2.8)

project(libcollections)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(include)

add_subdirectory(src)

add_subdirectory(tests)


