# Папка для сборки
BUILD_DIR := build

# Исполнимые файлы
MAIN_EXEC := client

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

# Очистка всех сгенерированных файлов и папок
clean:
	@echo "Очистка..."
	rm -rf $(BUILD_DIR)

.PHONY: all run clean build_and_run
