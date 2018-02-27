/*********************************************************************
** Author: Tony Huynh
** Date: 2/28/2018
** Description: This function increases each element of the original
** integer array by 1 and appends the results into the original array.
*********************************************************************/
#include <iostream>

void transformArray(int * &oldArrayPtr, const int SIZE) {
	// Allocate new array with double the size
	int *newArrayPtr = new int[SIZE * 2];

	// Copy old array elements to new array
	for (int i = 0; i < SIZE; i++) {
		newArrayPtr[i] = oldArrayPtr[i];
	}

	// Starting from the first element, add 1 and then append to end
	// of new array.
	for (int i = 0, j = SIZE; (i < SIZE) && (j < SIZE * 2); i++, j++) {
		newArrayPtr[j] = oldArrayPtr[i] + 1;
	}

	// Clean up
	delete [] oldArrayPtr;
	oldArrayPtr = newArrayPtr;	// Replace old array with new array address
}