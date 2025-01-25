cmake_minimum_required(VERSION 3.14)

project(PrimeCalculator)

set(CMAKE_CXX_STANDARD 17)

# Подключаем FetchContent
include(FetchContent)

# Загружаем spdlog
FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG v1.10.0
)

FetchContent_MakeAvailable(spdlog)

# Определение исходных файлов
set(SOURCE_FILES
    src/prime_calculator.cpp
    src/main.cpp
)

# Добавляем библиотеку
add_executable(main ${SOURCE_FILES})

# Линкуем spdlog
target_link_libraries(main spdlog::spdlog)

# Использование потоков
find_package(Threads REQUIRED)
target_link_libraries(main Threads::Threads)

# Папка для сборки
set(BUILD_DIR build)

# Исполнимые файлы
set(MAIN_EXEC main)

# Путь к CMake
#CMAKE := cmake
#MAKE := make


# Создание директории build, если она не существует
#$(BUILD_DIR):
#	@echo "Создание директории $(BUILD_DIR)"
#	mkdir -p $(BUILD_DIR)

# Запуск CMake и сборка
#$(BUILD_DIR)/Makefile: $(BUILD_DIR)
#	@echo "Запуск CMake..."
#	cd $(BUILD_DIR) && $(CMAKE) ..

# Сборка проекта
#all: $(BUILD_DIR)/Makefile
#	@echo "Сборка проекта..."
#	cd $(BUILD_DIR) && $(MAKE)

# Запуск основного приложения
#run: all
#	@echo "Запуск main..."
#	./$(BUILD_DIR)/$(MAIN_EXEC)

# Полный цикл: сборка и запуск приложения и тестов
#build_and_run: all run

# Очистка всех сгенерированных файлов и папок
#clean:
#	@echo "Очистка..."
#	rm -rf $(BUILD_DIR)

#.PHONY: all run clean build_and_run
