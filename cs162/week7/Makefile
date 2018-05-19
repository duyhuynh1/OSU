CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Queue.o main.o

TARGET = runTest

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)