/*********************************************************************
** Program name: Stack and Queue STL Containers
** Author: Tony Huynh
** Date: 6/03/1618
** Description: Driver program that allows user to test different
** types of characters in combat.
*********************************************************************/
#include "ExampleStackNQueueFunction.hpp"

/**
 *  Return the values stored in the buffer
 *  @param buffer - A queue of integers
 */
void printQueueValues(std::queue<int> buffer) {
    if (!buffer.empty()) {
        while (!buffer.empty()) {
            std::cout << buffer.front() << " ";
            buffer.pop();
        }
        std::cout << "\n";
    } else {
        std::cout << "buffer empty\n";
    }
}

/**
 *  Returns a string containing a palindrome using a stack of characters
 *  @param inputString - A stack of characters
 */
std::string createPalindrome(std::string inputString) {
    std::stack<char> mStack;
    std::string result = "";
    for (int i = 0; i < inputString.length(); i++) {
        mStack.push(inputString.at(i));
        result += mStack.top(); // Concatenate
    }
    // Traverse stack in reverse
    while (!mStack.empty()) {
        result += mStack.top(); // Concatenate
        mStack.pop();
    }
    return result;
}