cmake_minimum_required(VERSION 3.14)
project(password_cracker)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)

# Server
add_executable(server server/src/server.cpp)
target_link_libraries(server OpenSSL::Crypto Threads::Threads)

# Client
add_executable(client client/src/client.cpp)
target_link_libraries(client OpenSSL::Crypto Threads::Threads)
