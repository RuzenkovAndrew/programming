BUILD_DIR := build
MAIN_EXEC := main
CMAKE := cmake
MAKE := make

$(BUILD_DIR):
	@echo "Creating directory $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Running CMake..."
	cd $(BUILD_DIR) && $(CMAKE) ..

all: $(BUILD_DIR)/Makefile
	@echo "Building project..."
	cd $(BUILD_DIR) && $(MAKE)

run: all
	@echo "Running main..."
	./$(BUILD_DIR)/$(MAIN_EXEC) $(A) $(B) $(N)

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR)

.PHONY: all run clean
