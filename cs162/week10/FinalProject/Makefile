CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Menu.o Option.o Space.o \
		  ItemSpace.o PressurePlateSpace.o \
		  LockedItemSpace.o Player.o main.o

TARGET = ./runProgram

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)