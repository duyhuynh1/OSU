#include "Person.hpp"
#include "gtest/gtest.h"
#include <iostream>

// Function prototype
double stdDev(Person [], int);

int main() {
	const int SIZE = 5;
	Person people[SIZE] = { Person("A", 4.0),
							Person("B", 4.2),
							Person("C", 5.0),
							Person("D", 4.3),
							Person("E", 5.5) };
	std::cout << "Population Standard Deviation: "
			  << stdDev(people, SIZE) << std::endl;
	return 0;
}