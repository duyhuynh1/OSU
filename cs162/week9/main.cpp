/*********************************************************************
** Program name: Stack and Queue STL Containers
** Author: Tony Huynh
** Date: 6/03/1618
** Description: Driver program that allows user to simulate different
** standard template library containers: Stacks and Queues
*********************************************************************/
#include <iostream>
#include <queue>
#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */
#include "Menu.hpp"
#include "Option.hpp"
#include "ExampleStackNQueueFunction.hpp"

int main() {
    std::string mainMenuPrompt = "1. Queue simulation\n2. Stack simulation\n3. Exit\n=> ";
    std::string numOfroundsPrompt = "Please enter the number of rounds (max: 100): ";
    std::string appendPctPrompt = "Please enter the percentage to (append) a number: ";
    std::string removePctPrompt = "Please enter the percentage to (remove) a number: ";
    std::string stringPrompt = "Please enter a string: ";

    Option *option1 = new Option(mainMenuPrompt, 1, 3);
    Option *option2 = new Option(numOfroundsPrompt, 1, 100);
    Option *option3 = new Option(appendPctPrompt, 1, 100);
    Option *option4 = new Option(removePctPrompt, 1, 100);
    Option *option5 = new Option(stringPrompt);

    Menu mMenu;
    mMenu.addOption(option1);       // Index 0
    mMenu.addOption(option2);       // Index 1
    mMenu.addOption(option3);       // Index 2
    mMenu.addOption(option4);       // Index 3
    mMenu.addOption(option5);       // Index 4

    std::srand(std::time(0));       // Seeding random number generator

    std::queue<int> buffer;

    int N;                          // Randomly generated integer
    int rounds = 0;             // Number of simulated rounds
    int appendPct = 0;              // % chance of appending random number
    int removePct = 0;              // % chance of removing the first element in the queue
    double avgBufferLength = 0;      // Average buffer length

    std::string inputString = "";   // Empty string

    bool done = false;
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Stack and Queue Simulator\n";
    std::cout << std::string(50, '-') << std::endl;

    do {
        switch (mMenu.getUnsignedInteger(0)) {
            case 1:
                std::cout << std::string(50, '-') << std::endl;
                std::cout << "Integer Buffer (Queue Implementation)\n";
                std::cout << std::string(50, '-') << std::endl;
                rounds = mMenu.getUnsignedInteger(1);
                appendPct = mMenu.getUnsignedInteger(2);
                removePct = mMenu.getUnsignedInteger(3);
                for (int i = 1; i <= rounds; i++) {
                    N = rand() % 1000 + 1;      // Range 1 - 1000
                    if ((rand() % 100) + 1 <= appendPct) {         // Random roll append
                        buffer.push(N);
                    }
                    if ((rand() % 100) + 1 <= removePct) {
                        if (!buffer.empty()) {
                            buffer.pop();
                        }
                    }
                    std::cout << "round#: " << i << "\n";
                    std::cout << "Buffer {\n";
                    std::cout << "  values: ";
                    printQueueValues(buffer);
                    std::cout << "  length: " << buffer.size() << std::endl;
                    std::cout << "  average length: ";
                    // Formula: AL_i = (AL_i-1 * (i – 1) + L_i ) / i
                    avgBufferLength = (avgBufferLength * (i - 1) + buffer.size()) / i;
                    std::cout << avgBufferLength << "\n";
                    std::cout << "};\n";
                }
                break;
            case 2:
                std::cout << std::string(50, '-') << std::endl;
                std::cout << "String Palindrome (Stack Implementation)\n";
                std::cout << std::string(50, '-') << std::endl;
                inputString = mMenu.getString(4);
                std::cout << "input: " << inputString << std::endl;
                std::cout << "output: " << createPalindrome(inputString) << std::endl;
                break;
            case 3:
                done = true;
                std::cout << ">>> Exit program <<<";
                break;
        }
    } while (!done);

    delete option1;
    delete option2;
    delete option3;
    delete option4;
    delete option5;
    return 0;
}