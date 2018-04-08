/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: The function readMatrix() 
*********************************************************************/
// The readMatrix() function has two parameters:
// - @param ??? A pointer to a 2D array
// - @param ??? An integer as the size of the matrix
// [NOTE]: The function should prompt the user for all the numbers 
// within the matrix, that means for 2x2 matrix, it should ask the 
// user for 4 numbers, and 9 numbers for a 3x3 matrix. Because the
// function takes a pointer to the 2D array, it should not return anything.
#ifndef READMATRIX_HPP
#define READMATRIX_HPP

#include <iostream> // REMOVE

void readMatrix(int **aPtr, int size);

#endif  // READMATRIX_HPP