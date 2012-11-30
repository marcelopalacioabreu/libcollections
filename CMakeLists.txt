cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(libcollections)

set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(include)

# Compile and run tests based on CppUTest library (http://www.cpputest.org/)? 
option(COLL_RUN_TESTS "Compile and run tests based on CppUTest library (http://www.cpputest.org/)?" OFF)
set(COLL_CPPUTEST_LIBDIR "" CACHE PATH "CppUTest library directory")
set(COLL_CPPUTEST_INCDIR "" CACHE PATH "CppUTest include directory")

# Enable link with 
if(${COLL_RUN_TESTS})
	include_directories(${COLL_CPPUTEST_INCDIR})
	link_directories(${COLL_CPPUTEST_LIBDIR})
	add_definitions(-DCPPUTEST_ENABLED)
endif(${COLL_RUN_TESTS})

add_subdirectory(src)

if(${COLL_RUN_TESTS})
	enable_testing()	
	add_subdirectory(tests)
endif(${COLL_RUN_TESTS})
