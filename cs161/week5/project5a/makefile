CC = g++
CFLAGS = -std=c++0x -c -Wall

Box: boxMain.o Box.o
	$(CC) boxMain.o Box.o -o Box

boxMain.o: boxMain.cpp
	$(CC) $(CFLAGS) boxMain.cpp

Box.o: Box.cpp Box.hpp
	$(CC) $(CFLAGS) Box.cpp

clean:
	rm -rf *.o *.out