CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Game.o Dice.o HarryPotter.o Medusa.o BlueMen.o Vampire.o Barbarian.o Character.o main.o

TARGET = StartGame

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)