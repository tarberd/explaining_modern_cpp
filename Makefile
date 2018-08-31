CXX=g++
FLAGS=-std=c++14 -O3

.PHONY: all clean dir

all: main.cpp dir
	$(CXX) main.cpp -I. -o bin/main $(FLAGS)

dir:
	mkdir -p bin

run: all
	bin/main

clean:
	rm -rf *.o
	rm -rf bin/main
