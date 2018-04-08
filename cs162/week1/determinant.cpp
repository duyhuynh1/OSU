/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Matrix calculator determinant calculation implemented
*********************************************************************/
#include "determinant.hpp"

int determinant(int **aPtr, int size) {

    switch (size) {
        case 2:
            std::cout << "[D]: calculating determinant of 2x2 matrix\n";    // REMOVE
            return aPtr[0][0] * aPtr[1][1] - aPtr[0][1] * aPtr[1][0];
            break;
        case 3:
            std::cout << "[D]: calculating determinant of 3x3 matrix\n";    // REMOVE
            return aPtr[0][0] * (aPtr[1][1] * aPtr[2][2] - aPtr[1][2] * aPtr[2][1])
                 - aPtr[0][1] * (aPtr[1][0] * aPtr[2][2] - aPtr[1][2] * aPtr[2][0])
                 + aPtr[0][2] * (aPtr[1][0] * aPtr[2][1] - aPtr[1][1] * aPtr[2][0]);
            break;
    }
    return -1;  // If error
}