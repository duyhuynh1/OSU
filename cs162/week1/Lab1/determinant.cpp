/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Matrix calculator determinant calculation implemented.
** Given a square matrix this function returns the matrix's 
** determinant.
*********************************************************************/
#include "determinant.hpp"

/**
 *  Calculates the determinant of a square matrix.
 * 
 *  @param aPtr A pointer to a 2D array
 *  @param size An integer representing the size of the matrix
 */
int determinant(int **aPtr, int size) {

    if (size == 2) {
        return aPtr[0][0] * aPtr[1][1] - aPtr[0][1] * aPtr[1][0];
    } else {
        return aPtr[0][0] * (aPtr[1][1] * aPtr[2][2] - aPtr[1][2] * aPtr[2][1])
             - aPtr[0][1] * (aPtr[1][0] * aPtr[2][2] - aPtr[1][2] * aPtr[2][0])
             + aPtr[0][2] * (aPtr[1][0] * aPtr[2][1] - aPtr[1][1] * aPtr[2][0]);
    }

}