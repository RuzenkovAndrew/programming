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
	touch result_file.txt
	
build:
	
	dd if=/dev/urandom of=huge_file.txt bs=1M count=1000
	$(CC) -c src/entropy_calculator.cpp -o obj/entropy_calculator.o
	$(CC) -c src/main.cpp -o obj/main.o
	$(CC) -o bin/main.p obj/main.o obj/entropy_calculator.o
	

