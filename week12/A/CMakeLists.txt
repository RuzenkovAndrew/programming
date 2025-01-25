cmake_minimum_required(VERSION 3.14)

project(prime_finder)

set(CMAKE_CXX_STANDARD 17)

# Подключаем FetchContent
include(FetchContent)

# Загружаем spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.9.2  # Измените на более старую версию, если необходимо
)

FetchContent_MakeAvailable(spdlog)

# Определение исходных файлов
set(SOURCE_FILES
    src/prime_finder.cpp
    src/main.cpp
)

# Добавляем исполняемый файл
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Линкуем spdlog
target_link_libraries(${PROJECT_NAME} spdlog::spdlog)

# Использование потоков
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} Threads::Threads)

