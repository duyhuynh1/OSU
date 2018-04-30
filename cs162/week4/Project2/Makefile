CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = Zoo.o Tiger.o Animal.o main.o

TARGET = ZooTycoon

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)