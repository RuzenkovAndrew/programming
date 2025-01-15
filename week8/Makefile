# Папка для сборки
BUILD_DIR := build

# Исполнимые файлы
MAIN_EXEC := main

# Путь к CMake
CMAKE := cmake
MAKE := make

# Создание директории build, если она не существует
$(BUILD_DIR):
	@echo "Создание директории $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

# Запуск CMake и сборка
$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Запуск CMake..."
	cd $(BUILD_DIR) && $(CMAKE) ..

# Сборка проекта
all: $(BUILD_DIR)/Makefile
	@echo "Сборка проекта..."
	cd $(BUILD_DIR) && $(MAKE)

# Запуск основного приложения
run: all
	@echo "Запуск main..."
	./$(BUILD_DIR)/$(MAIN_EXEC)

# Полный цикл: сборка и запуск приложения и тестов
build_and_run: all run

# Очистка всех сгенерированных файлов и папок
clean:
	@echo "Очистка..."
	rm -rf $(BUILD_DIR)

.PHONY: all run test clean build_and_run
