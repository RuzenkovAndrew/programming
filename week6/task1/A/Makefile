SHELL=/bin/bash
INC=-Iinclude
CC=g++

all: clean prepare build
	@echo "Building application...done"
	echo $(SHELL)

clean:
	rm -rf bin
	rm -rf obj

prepare:
	mkdir -p bin
	mkdir -p obj

build:
	$(CC) -c src/permutations.cpp -o obj/permutations.o
	$(CC) -c src/main.cpp -o obj/main.o
	$(CC) -o bin/main.p obj/main.o obj/permutations.o
