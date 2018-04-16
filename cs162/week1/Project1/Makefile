CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Menu.o Ant.o Board.o main.o

TARGET = langtonAntSimulation

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)