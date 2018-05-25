/*********************************************************************
** Program name: Circular Linked List
** Author: Tony Huynh
** Date: 5/19/2018
** Description: Implements a Queue data structure to demonstrate to
** the user how a Circular Linked List operates.
*********************************************************************/
#include <iostream>
#include <climits>
#include "Queue.hpp"
#include "Menu.hpp"
#include "Option.hpp"

int main() {
    std::string mainMenuPrompt = "\nChoose from following options: \n\n"
                                 "  1. Enter a value to be added to the back of queue\n"
                                 "  2. Display first node (front) value\n"
                                 "  3. Remove first node (front) value\n"
                                 "  4. Move first node (front) to the back of queue\n"
                                 "  5. Display the queue contents\n"
                                 "  6. Exit\n"
                                 "=> ";
    std::string positiveIntegerPrompt = "Please enter an integer: ";
    Option *option1 = new Option(mainMenuPrompt, 1, 6);
    Option *option2 = new Option(positiveIntegerPrompt, INT_MIN, INT_MAX);
    Menu mMenu;
    mMenu.addOption(option1);   // Index 0
    mMenu.addOption(option2);   // Index 1

    Queue *mQueue = new Queue();

    bool done = false;
    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Welcome to my Queue!" << std::endl;
    std::cout << std::string(50, '=') << std::endl;
    do {
        switch (mMenu.getUnsignedInteger(0)) {
            case 1:
                mQueue->addBack(mMenu.getSignedInteger(1));
                break;
            case 2:
                if (mQueue->getFront() != 0) {
                    std::cout << "[INFO]: Queue is empty...\n";
                }
                break;
            case 3:
                mQueue->removeFront();
                break;
            case 4:
                mQueue->moveFrontToBack();
                break;
            case 5:
                mQueue->printQueue();
                break;
            case 6:
                std::cout << ">>> Exit Program <<<" << std::endl;
                done = true;
                break;
        }
    } while (!done);

    delete option1;
    delete option2;
    delete mQueue;
    return 0;
}