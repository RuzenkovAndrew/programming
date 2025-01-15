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
	$(CC) -c src/Book.cpp -o obj/Book.o
	$(CC) -c src/Author.cpp -o obj/Author.o
	$(CC) -c src/main.cpp -o obj/main.o
	$(CC) -o bin/main obj/main.o obj/Author.o obj/Book.o
