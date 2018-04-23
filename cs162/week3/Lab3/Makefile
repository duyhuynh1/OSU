CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Option.o Menu.o Game.o Player.o LoadedDie.o Die.o main.o

TARGET = diceWarGame

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)