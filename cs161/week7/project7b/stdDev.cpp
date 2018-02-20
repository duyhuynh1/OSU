/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Calculates the standard deviation of ages in a group
** of people.
*********************************************************************/
#include "Person.hpp"
#include <cmath>

// Function prototype
double stdDev(Person [], int);

double stdDev(Person people[], int size) {
	double result;
	double totalAge = 0.0;
	double mean = 0.0;
	double summation = 0.0;
	double variance = 0.0;
	// Calculate the mean age of the group of people
	for (int i = 0; i < size; i++) {
		totalAge += people[i].getAge();
	}
	mean = totalAge / size;
	// Calculate the population variance
	for (int i = 0; i < size; i++) {
		summation += pow((people[i].getAge() - mean), 2);
	}
	variance = summation / size;
	// Return the population standard deviation
	return result = sqrt(variance);
}