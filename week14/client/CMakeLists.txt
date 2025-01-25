cmake_minimum_required(VERSION 2.8)

project(ChatApplication)

set(SOURCE_CLIENT src/client.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(client ${SOURCE_CLIENT})
target_link_libraries(client Threads::Threads)

