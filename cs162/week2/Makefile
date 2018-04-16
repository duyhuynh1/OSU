CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = file_io.o main.o

TARGET = fileIO

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)