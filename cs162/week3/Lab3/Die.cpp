#include "Die.hpp"

/**
 *  Die constructor
 */
Die::Die(int side) {
    std::cout << "Die constructor" << std::endl;        // REMOVE
    numberOfSides = side;
}

Die::~Die() {
    std::cout << "~Die() destructor called" << std::endl;   // REMOVE
}

int Die::roll() {
    std::cout << "Die::roll() called" << std::endl;     // REMOVE
    srand(time(NULL));
    return (rand() % numberOfSides) + 1;
}