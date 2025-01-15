SHELL=/bin/bash
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
	$(CC) -Wall -g -O0 -c src/main.cpp -o obj/main.o
	$(CC) -g -O0 -o bin/main.p obj/main.o

