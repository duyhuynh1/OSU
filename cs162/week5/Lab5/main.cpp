/*********************************************************************
** Program name: Recursive Functions
** Author: Tony Huynh
** Date: 5/6/2018
** Description: Driver program that allows the user to invoke 3 
** different type of recursive functions.
*********************************************************************/
#include <iostream>
#include <climits>      // INT_MIN, INT_MAX
#include "RecursiveFunction.hpp"
#include "Menu.hpp"
#include "Option.hpp"

void functionReverseString(Menu &);
void functionSumIntArray(Menu &);
void functionCalcTriangularValue(Menu &);

int main() {
    std::string mainMenuPrompt = "0. Exit\n"
                                 "1. Print a string in reverse\n"
                                 "2. Calculate the sum of an array of integers\n"
                                 "3. Calculate the triangular number of an integer N\n"
                                 "> ";
    std::string func1Prompt = "Please enter a string: ";
    std::string func2Prompt = "Please enter the number of integers in the array: ";
    std::string func3Prompt = "Please enter an integer N {0 - 100}: ";
    Menu mMenu;
    Option *mainOption = new Option(mainMenuPrompt, 0, 3);
    Option *option1    = new Option(func1Prompt);
    Option *option2    = new Option(func2Prompt, 1, 100);
    Option *option3    = new Option(func3Prompt, 0, 100); 

    mMenu.addOption(mainOption);    // Index 0
    mMenu.addOption(option1);       // Index 1
    mMenu.addOption(option2);       // Index 2
    mMenu.addOption(option3);       // Index 3

    bool exit = false;
    do {
        std::cout << std::string(50, '=') << "\n"
                  << "RECURSIVE FUNCTIONS\n"
                  << std::string(50, '=') << "\n";
        switch (mMenu.getValue(0)) {
            case 0:
                exit = true;
                std::cout << ">>> Exiting Program <<<" << std::endl;
                break;
            case 1:
                functionReverseString(mMenu);
                break;
            case 2:
                functionSumIntArray(mMenu);
                break;
            case 3:
                functionCalcTriangularValue(mMenu);
                break;
        }
    } while (!exit);

    delete mainOption;
    delete option1;
    delete option2;
    delete option3;
    return 0;
}

void functionReverseString(Menu &mMenu) {
    std::string userInput = mMenu.getString(1);
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "[INPUT]:  " << userInput << "\n";
    std::cout << "[OUTPUT]: ";
    reverseString(userInput);
    std::cout << std::endl;
}

void functionSumIntArray(Menu &mMenu) {
    int size = mMenu.getValue(2);
    int * ptrArrayInt = new int[size];
    for (int i = 0; i < size; i++) {
        std::string number = "";
        int result;
        bool valid = false;
        do {
            try {
                std::cout << "Please enter number[" << i << "]: ";
                while (std::getline(std::cin, number) &&
                       number.find_first_not_of("1234567890-") != std::string::npos) {
                    std::cout << "Please enter number[" << i << "]: ";
                }
                if (number.size() == 0) {
                } else {
                    result = stoi(number);
                    if (result >= INT_MIN && result <= INT_MAX) {
                        valid = true;
                    }
                }
            } catch (std::invalid_argument) {
                // Invalid argument exception caught (e.g., " ")
            } catch (std::out_of_range) {
                // Out of range exception caught (e.g., " ")
            }
        } while (!valid);
        ptrArrayInt[i] = result;
    }
    std::cout << "[INPUT]: [ ";
    for (int i = 0; i < size; i++) {
        if (i == size - 1) {    // Last element don't display ','
            std::cout << ptrArrayInt[i] << " ]\n"; 
        } else {
            std::cout << ptrArrayInt[i] << ", ";   
        }
    }
    std::cout << "[OUTPUT]: " << sumIntArray(ptrArrayInt, size) << std::endl;
    delete [] ptrArrayInt;
}

void functionCalcTriangularValue(Menu &mMenu) {
    int number = mMenu.getValue(3);
    std::cout << "[INPUT]: " << number << std::endl;
    std::cout << "[OUTPUT]: " << calcTriangularNum(number) << std::endl;
}