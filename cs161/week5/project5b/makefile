CC = g++

CFLAGS = -std=c++0x -c -Wall

Taxicab: taxicabMain.o Taxicab.o
	$(CC) taxicabMain.o Taxicab.o -o Taxicab

taxicabMain.o: taxicabMain.cpp
	$(CC) $(CFLAGS) taxicabMain.cpp

Taxicab.o: Taxicab.cpp Taxicab.hpp
	$(CC) $(CFLAGS) Taxicab.cpp

clean:
	rm -rf *.o *.out