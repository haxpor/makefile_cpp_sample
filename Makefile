.PHONY: all clean main lib test

all: main

lib: libutil.so

libutil.so: util.o
	g++ -shared -o libutil.so util.o

util.o: util.cpp util.h
	g++ -Wall -Wextra -std=c++17 -fPIC -c util.cpp

main: lib main.out

main.out: main.o
	g++ -o main.out main.o -lutil -L./

main.o: main.cpp
	g++ -Wall -Wextra -std=c++17 -c main.cpp -o main.o -I./

test: all
	./main.out

clean:
	rm -rf *.out *.o *.so
