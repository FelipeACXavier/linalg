cmake_minimum_required(VERSION 3.5.1)

# Define project name
project(linalg VERSION 1.0)

add_compile_options(-O3)

option(BUILD_TESTS "Build the test code" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if( BUILD_TESTS )
  enable_testing ()
  add_subdirectory (test)
endif()

add_subdirectory(src)