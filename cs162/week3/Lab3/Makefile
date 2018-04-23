CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Menu.o Game.o Player.o LoadedDie.o Die.o main.o

TARGET = warGame

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)