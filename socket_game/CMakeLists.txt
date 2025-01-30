cmake_minimum_required(VERSION 3.10)
project(socket_game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(nlohmann_json REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)

# Поиск SQLite3
find_package(SQLite3 REQUIRED)
if(NOT SQLite3_FOUND)
    message(FATAL_ERROR "SQLite3 not found. Please make sure it's installed.")
endif()

# Поиск библиотеки fmt
find_package(fmt REQUIRED)

add_executable(my_socket_game main.cpp)
add_executable(my_socket_server server.cpp)

# Связывание с SQLite3 и fmt
target_link_libraries(my_socket_game PRIVATE nlohmann_json::nlohmann_json ${SQLite3_LIBRARIES} fmt::fmt)
target_link_libraries(my_socket_server PRIVATE nlohmann_json::nlohmann_json ${SQLite3_LIBRARIES} fmt::fmt)

# Создание директории сборки
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})

# Цели для сборки
add_custom_target(build_all DEPENDS my_socket_game my_socket_server)

# Цели для выполнения
add_custom_command(
    TARGET build_all
    COMMAND ${CMAKE_COMMAND} -E echo "Building client..."
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target my_socket_game
)

add_custom_command(
    TARGET build_all
    COMMAND ${CMAKE_COMMAND} -E echo "Building server..."
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target my_socket_server
)

# Цели для запуска
add_custom_target(run_client
    COMMAND ${CMAKE_COMMAND} -E echo "Running client..."
    COMMAND ${CMAKE_COMMAND} -E execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/my_socket_game)
)

add_custom_target(run_server
    COMMAND ${CMAKE_COMMAND} -E echo "Running server..."
    COMMAND ${CMAKE_COMMAND} -E execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/my_socket_server)
)

# Цель для очистки
add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -E echo "Cleaning..."
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
)


