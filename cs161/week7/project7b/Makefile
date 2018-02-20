GOOGLE_TEST_LIB = gtest
GOOGLE_TEST_INCLUDE = /usr/local/include
CC = g++
CFLAGS = -std=c++0x -c -Wall -I $(GOOGLE_TEST_INCLUDE)
LD_FLAGS = -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread
OBJECTS = Person.o stdDev.o unitTest.o

TARGET = stdDev

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LD_FLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) $<

clean:
	rm -f $(TARGET) $(OBJECTS)