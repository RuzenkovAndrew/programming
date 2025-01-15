cmake_minimum_required(VERSION 3.14)

project(Fibonacci LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(JSON_Install OFF CACHE INTERNAL "")

include_directories("include")
add_library(fibonacci STATIC src/fibonacci.cpp)
add_executable(main src/main.cpp)
target_link_libraries(main fibonacci)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  fibonacci_test
  tests/fibonacci_test.cpp
)
target_link_libraries(
  fibonacci_test
  fibonacci
  GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(fibonacci_test)
