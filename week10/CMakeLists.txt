cmake_minimum_required(VERSION 3.14)

project(StackExample LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Устанавливаем путь к заголовочным файлам
include_directories(include)

# Сборка основного исполнимого файла
add_executable(main src/main.cpp)
target_include_directories(main PUBLIC src) # Указываем директорию с заголовочными файлами


# Сборка Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Включение тестирования
enable_testing()

# Сборка тестов
add_executable(
  stack_test
  tests/stack_test.cpp
)
target_link_libraries(
  stack_test
  GTest::gtest_main
)

# Автоматическое обнаружение тестов
include(GoogleTest)
gtest_discover_tests(stack_test)
