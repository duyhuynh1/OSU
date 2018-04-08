/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Implements the readMatrix function
*********************************************************************/
// REF: https://gsamaras.wordpress.com/code/dynamic-2d-array-in-c/ REMOVE

#include "readMatrix.hpp"

void readMatrix(int **aPtr, int size) {
    std::cout << "[D]: inside readMatrix()" << std::endl;
    int num;
    
    // Printing unfilled Matrix REMOVE all of this
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << aPtr[i][j] << " ";
        }
        std::cout << "\n";
    }
    // REMOVE 


    // Fill matrix with user input
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // TODO: Input validation for only numbers
            std::cout << "Enter a number: ";
            std::cin >> num;
            while (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cout << "Enter a number: ";
                std::cin >> num;
            }
            // Fill in if valid
            aPtr[i][j] = num;
        }
    }

}