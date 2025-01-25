cmake_minimum_required(VERSION 3.10)

project(ChatApplication)

include_directories(include)

set(SOURCE_FILES 
    src/server.cpp
    src/server_func.cpp
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(server ${SOURCE_FILES})

target_link_libraries(server Threads::Threads)
