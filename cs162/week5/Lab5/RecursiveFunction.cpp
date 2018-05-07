/*********************************************************************
** Program name: Recursive Functions
** Author: Tony Huynh
** Date: 5/6/2018
** Description: Driver program that allows the user to invoke 3 
** different type of recursive functions.
*********************************************************************/
#include "RecursiveFunction.hpp"

/**
 *  Prints a string in reverse
 *  @param word A string object containg the user's input
 */
void reverseString(std::string word) {
    int position = word.length() - 1;
    if (position == 0) {
        std::cout << word.at(0) << std::endl;
    } else {
        std::cout << word.at(position);
        word.resize(position);
        reverseString(word);
    }
}

/**
 *  Calculates the sum of an array of integers
 *  @param arrayInt A pointer to the integer array
 *  @param numElements An integer for the number of elements in the array
 */
int sumIntArray(int * arrayInt, int numElements) {
    if (numElements <= 0) {
        return 0;
    } else {
        return sumIntArray(arrayInt, numElements - 1) + arrayInt[numElements - 1];
    }
}

/**
 *  Calculates the triangular number of an integer N
 *	@param number An integer depicting the base triangular number
 */
int calcTriangularNum(int number) {
    if (number <= 1) {
        return number;
    }
    return calcTriangularNum(number - 1) + number;
}