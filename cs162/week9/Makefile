CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Option.o Menu.o ExampleStackNQueueFunction.o main.o

TARGET = ./runProgram

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)