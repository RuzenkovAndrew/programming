cmake_minimum_required(VERSION 2.8)

project(Fibonacci)

set(SOURCE_EXE src/main.cpp)

set(SOURCE_LIB src/fibonacci.cpp)

add_library(fibonacci STATIC ${SOURCE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main fibonacci)
