CC = g++

CFLAGS = -std=c++0x -c -Wall

all: Box

Box: boxMain.o Box.o
	$(CC) boxMain.o Box.o

boxMain.o: boxMain.cpp
	$(CC) $(CFLAGS) boxMain.cpp

Box.o: Box.cpp Box.hpp
	$(CC) $(CFLAGS) Box.cpp

clean:
	rm -rf Box