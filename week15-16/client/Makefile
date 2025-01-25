CC = g++
CFLAGS = -Wall -g -std=c++11 -lcrypto -lpthread

# Source directories
CLIENT_DIR = src

# Source files
CLIENT_SRC = $(CLIENT_DIR)/client.cpp

# Executable names
CLIENT_EXE = client

BUILD_DIR = ../build/client

all: $(BUILD_DIR)/$(CLIENT_EXE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(CLIENT_EXE): $(CLIENT_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CLIENT_SRC) -o $(BUILD_DIR)/$(CLIENT_EXE)

run: all
	@echo "Running client..."
	./$(BUILD_DIR)/$(CLIENT_EXE)

run_workers_3: all
	@echo "Running 3 clients..."
	./$(BUILD_DIR)/$(CLIENT_EXE) &
	./$(BUILD_DIR)/$(CLIENT_EXE) &
	./$(BUILD_DIR)/$(CLIENT_EXE)

clean:
	rm -rf $(BUILD_DIR)
