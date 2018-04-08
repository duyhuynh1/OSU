/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: This application provides the user with the options to
** select a 2x2 or 3x3 square matrix. The user will be prompted to 
** enter numbers into the matrix and then the matrix's determinant is
** calculated and displayed.
*********************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

void displayMenu();

int main() {
    int selection;
    int size;
    bool validSelection = false;

    do {
        displayMenu();
        std::cin >> selection;

        // Input validation 
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(256, '\n');
            displayMenu();
            std::cin >> selection;
        }

        // Check if selection is in range
        if (selection >= 0 && selection <= 2) {
            if (selection == 0) {
                size = 0;
            } else {
                size = (selection == 1) ? 2 : 3;
            }
            validSelection = true;
        }

    } while (!validSelection);

    if (size == 0) {
        std::cout << "<<< Program Closed >>>" << std::endl;
        return 0;
    } else {
        // Dynamically allocating memory for 2D array
        int **aPtr = new int *[size];
        for (int i = 0; i < size; i++) {
            aPtr[i] = new int[size];
        }

        readMatrix(aPtr, size);

        // Display Matrix
        std::cout << "------------------------------------\n";
        std::cout << "MATRIX:\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                std::cout << aPtr[i][j] << " ";
            }
            std::cout << "\n";
        }

        // Determinant results
        std::cout << "RESULT:\n";
        std::cout << "det A = " << determinant(aPtr, size) << std::endl;
        std::cout << "------------------------------------\n";

        // Free memory
        for (int i = 0; i < size; i++) {
            delete [] aPtr[i];
        }
        delete [] aPtr;
        return 0;
    }
}

void displayMenu() {
    std::cout << "====================================\n";
    std::cout << "Please select the size of the matrix\n";
    std::cout << "====================================\n";
    std::cout << "0 - >>> QUIT <<<\n";
    std::cout << "1 - 2x2 Matrix\n";
    std::cout << "2 - 3x3 Matrix\n";
    std::cout << "Selected option: ";
}