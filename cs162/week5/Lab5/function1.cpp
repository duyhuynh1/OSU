#include "function1.hpp"

/**
 *  Prints a string in reverse
 *  @param word A string object containg the user's input
 */
void reverseString(std::string word) {
    int position = word.length() - 1;
    if (position == 0) {
        std::cout << word.at(0) << std::endl;
    } else {
        std::cout << word.at(position);
        word.resize(position);
        reverseString(word);
    }
}

/**
 *  Calculates the sum of an array of integers
 *  @param arrayInt A pointer to the integer array
 *  @param numElements An integer for the number of elements in the array
 */
int sumIntArray(int ** arrayInt, int numElements) {
        
    // if (numElements == ) {
    //     return 
    // } else {
    //     sumIntArray();
    // }
}

/**
 *  Calculates the triangular number of an integer N
 */
int calcTriangularNum(int &) {
    // TODO:
}