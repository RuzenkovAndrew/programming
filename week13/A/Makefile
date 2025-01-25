# Исполнимые файлы
MAIN_EXEC := main
BUILD_DIR := build

# Сборка проекта
all: clean
	@echo "Сборка проекта..."
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && make

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

.PHONY: all run clean build_and_run
