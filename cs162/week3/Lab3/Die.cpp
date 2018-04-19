#include "Die.hpp"

/**
 *  Die constructor
 */
Die::Die(int side) {
    std::cout << "Die constructor" << std::endl;
    numberOfSides = side;
}

int Die::roll() {
    srand(time(NULL));
    return (rand() % numberOfSides) + 1;
}