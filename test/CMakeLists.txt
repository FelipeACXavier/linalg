cmake_minimum_required(VERSION 3.5.1)

# Define project name
set(VECTOR vector_gtests)
set(MATRIX matrix_gtests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(GoogleTest)
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)

FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(${VECTOR} vector_test.cpp)
add_executable(${MATRIX} matrix_test.cpp)

target_link_libraries(${VECTOR}
  PRIVATE
    GTest::GTest
    linalg
)

target_link_libraries(${MATRIX}
  PRIVATE
    GTest::GTest
    linalg
)

gtest_discover_tests(${VECTOR})
gtest_discover_tests(${MATRIX})

find_package(SDL2 REQUIRED)
add_executable(waves main.cpp)

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(waves linalg)
target_link_libraries(waves ${SDL2_LIBRARIES})