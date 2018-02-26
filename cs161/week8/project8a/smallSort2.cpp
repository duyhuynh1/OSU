/*********************************************************************
** Author: Tony Huynh
** Date: 2/28/2018
** Description: Sorting function that takes 3 integer arguments and 
** sorts them in ascending order. This implementation utilizes 
** pointers to achieve the desired results.
*********************************************************************/
#include <iostream>

void swap(int *, int *);

void smallSort2(int *aPtr, int *bPtr, int *cPtr) {
	if (*aPtr > *bPtr) { swap(aPtr, bPtr); }
	if (*bPtr > *cPtr) { swap(bPtr, cPtr); }
	if (*aPtr > *bPtr) { swap(aPtr, bPtr); }
}

void swap(int *num1, int *num2) {
	int temp;
	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}