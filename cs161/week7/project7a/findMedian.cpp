/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Finds the median number from an array of integers.
*********************************************************************/
#include <algorithm>

// Function prototype
double findMedian(int [], int);

double findMedian(int intArray[], int size) {
	double median = 0;
	// Sort array in ascending order
	std::sort(intArray, intArray + size);	
	if (size % 2 == 0) {
		// Find the median of an even number array			
		double central1 = intArray[size / 2 - 1];
		double central2 = intArray[size / 2];
		return median = (central1 + central2) / 2;
	} else {
		// Find the median of an odd number array								
		return median = intArray[size / 2];
	}
}