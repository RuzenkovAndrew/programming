CC = g++
CFLAGS = -Wall -g -std=c++11 -lcrypto -lpthread

# Source directories
SERVER_DIR = src

# Source files
SERVER_SRC = $(SERVER_DIR)/server.cpp

# Executable names
SERVER_EXE = server

BUILD_DIR = ../build/server

all: $(BUILD_DIR)/$(SERVER_EXE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/$(SERVER_EXE): $(SERVER_SRC) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SERVER_SRC) -o $(BUILD_DIR)/$(SERVER_EXE)

run: all
	@echo "Running server..."
	./$(BUILD_DIR)/$(SERVER_EXE)

clean:
	rm -rf $(BUILD_DIR)
