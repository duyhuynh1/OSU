CC = g++
CFLAGS = -std=c++0x -c -g -Wall
OBJECTS = University.o Building.o Instructor.o Student.o Person.o Menu.o Option.o main.o

TARGET = OSUInformationSystem

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -rf $(TARGET)* $(OBJECTS)