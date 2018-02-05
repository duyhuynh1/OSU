/*********************************************************************
** Author: Tony Huynh
** Date: 1/31/2018
** Description: Sorting function that takes 3 integer arguments and 
** sorts them in ascending order.
*********************************************************************/
#include <iostream>

// Function prototype
void smallSort(int &a, int &b, int &c);
void swap(int &num1, int &num2); // only used by smallSort()

void smallSort(int &a, int &b, int &c) {
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
}

void swap(int &num1, int &num2) {
    // Swap values using local temp variable
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}