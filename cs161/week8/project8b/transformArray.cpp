/*********************************************************************
** Author: Tony Huynh
** Date: 2/28/2018
** Description: This function replaces the original array with one 
** that is twice as long, with the values from the original array
** followed by each of those values plus one.
*********************************************************************/

void transformArray(int * &oldArrayPtr, const int SIZE) {
	// Allocate new array with double the size
	int *newArrayPtr = new int[SIZE * 2];

	// Copy old array elements to new array
	for (int i = 0; i < SIZE; i++) {
		newArrayPtr[i] = oldArrayPtr[i];
	}

	// Add 1 to each value in old array and append result to new array
	for (int i = 0, j = SIZE; (i < SIZE) && (j < SIZE * 2); i++, j++) {
		newArrayPtr[j] = oldArrayPtr[i] + 1;
	}

	// Clean up
	delete [] oldArrayPtr;
	oldArrayPtr = newArrayPtr;	// Replace old array with new array address
}