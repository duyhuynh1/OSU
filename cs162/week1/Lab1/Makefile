CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = determinant.o readMatrix.o main.o

TARGET = matrixCalculator

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)