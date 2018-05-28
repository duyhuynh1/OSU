CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Menu.o Option.o Queue.o Tournament.o Dice.o \
 		  Barbarian.o Character.o main.o

TARGET = StartGame

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)