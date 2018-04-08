/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: The function readMatrix() prompts the user for 4 or 9
** integer inputs depending on the selected matrix size.
*********************************************************************/
#include "readMatrix.hpp"

/**
 *  Prompts the user for 4 or 9 integer inputs depending on the 
 *  select matrix size.
 *  
 *  @param aPtr A pointer to a 2D array
 *  @param size An integer representing the size of the matrix
 */
void readMatrix(int **aPtr, int size) {
    int num;

    // Fill matrix with user input
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << "Enter a number: ";
            std::cin >> num;

            // Input validati
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Enter a number: ";
                std::cin >> num;
            }
            aPtr[i][j] = num;
        }
    }

}