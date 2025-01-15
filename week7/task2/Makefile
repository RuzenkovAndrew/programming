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
	$(CC) -Wall -g -O0 -c $(INC) -o obj/customer.o src/customer.cpp
	$(CC) -Wall -g -O0 -c $(INC) -o obj/order.o src/order.cpp
	$(CC) -Wall -g -O0 -c $(INC) -o obj/product.o src/product.cpp
	$(CC) -Wall -g -O0 -c $(INC) -o obj/main.o src/main.cpp
	$(CC) -Wall -g -O0 -c $(INC) -o obj/date.o src/date.cpp
	$(CC) -g -O0 -o bin/main.p obj/customer.o obj/order.o obj/date.o obj/product.o obj/main.o
