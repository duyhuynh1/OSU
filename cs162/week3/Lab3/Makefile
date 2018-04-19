CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = LoadedDie.o Die.o main.o

TARGET = warGame

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)