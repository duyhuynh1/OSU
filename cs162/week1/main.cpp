/*********************************************************************
** Program name: Matrix Calculator
** Author: Tony Huynh
** Date: 04/08/2018
** Description: Matrix Calculator main function
*********************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

void displayMenu();

int main() {
    int choice;
    int size;
    bool valid = false;

    do {
        displayMenu();
        std::cin >> choice;

        while (std::cin.fail()) {
            std::cin.clear();               // Clear input buffer
            std::cin.ignore(256, '\n');     // ???
            displayMenu();
            std::cin >> choice;
        }

        valid = true;
    } while (!(choice >= 1 && choice <= 2 && valid));
    std::cout << "[D]: User selected " << choice << std::endl;  // REMOVE

    size = (choice == 1) ? 2 : 3;

    // aPtr[i] = *aPtr REMOVE
    // Dynamically allocating memory for 2D array
    int **aPtr = new int *[size];
    for (int i = 0; i < size; i++) {
        aPtr[i] = new int[size];          // Each pointer points to an 1D array
    }

    // Call readMatrix
    readMatrix(aPtr, size);

    std::cout << "[D]: after user input\n"; // REMOVE
    // Display Matrix
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << aPtr[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Determinant results
    std::cout << "det A = " << determinant(aPtr, size) << std::endl;
    // Free memory
    for (int i = 0; i < size; i++) {
        delete [] aPtr[i];
    }
    delete [] aPtr;

    std::cout << "[D]: Program complete..." << std::endl;  // REMOVE
}

void displayMenu() {
    std::cout << "====================================\n";  // TODO: How to dynamically resize??
    std::cout << "Please select the size of the matrix\n";
    std::cout << "====================================\n";
    std::cout << "1 - 2x2 Matrix\n";
    std::cout << "2 - 3x3 Matrix\n";
    std::cout << "Selected option: ";
}