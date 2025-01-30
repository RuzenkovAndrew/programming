BUILD_DIR := build
MAIN_EXEC := my_socket_game
MAIN_SERVER := my_socket_server
CMAKE := cmake
MAKE := make

$(BUILD_DIR):
	@echo "Creating directory $(BUILD_DIR)"
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	@echo "Running CMake..."
	cd $(BUILD_DIR) && $(CMAKE) ..

all: $(BUILD_DIR)/$(MAIN_EXEC) $(BUILD_DIR)/$(MAIN_SERVER)

$(BUILD_DIR)/$(MAIN_EXEC): $(BUILD_DIR)/Makefile
	@echo "Building client..."
	cd $(BUILD_DIR) && $(MAKE) my_socket_game

$(BUILD_DIR)/$(MAIN_SERVER): $(BUILD_DIR)/Makefile
	@echo "Building server..."
	cd $(BUILD_DIR) && $(MAKE) my_socket_server

run: $(BUILD_DIR)/$(MAIN_EXEC)
	@echo "Running main..."
	./$(BUILD_DIR)/$(MAIN_EXEC)

run_server: $(BUILD_DIR)/$(MAIN_SERVER)
	@echo "Running server..."
	./$(BUILD_DIR)/$(MAIN_SERVER)

clean:
	@echo "Cleaning..."
	rm -rf $(BUILD_DIR)

.PHONY: all run clean $(BUILD_DIR)

