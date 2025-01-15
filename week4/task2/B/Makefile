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
	$(CC) -c src/ipv6_checker.cpp -o obj/ipv6_checker.o
	$(CC) -c src/main.cpp -o obj/main.o
	$(CC) -o bin/main.p obj/main.o obj/ipv6_checker.o
