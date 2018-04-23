/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Die class is the base class that provides all
** the necessary properties to create a Die object. It stores the
** number of sides and the roll function simulats a dice roll.
*********************************************************************/
#include "Die.hpp"

/**
 *  Die constructor
 */
Die::Die(int side) {
    numberOfSides = side;
    std::srand(std::time(0));
}

/**
 *	Die default destructor
 */
Die::~Die() { }

/**
 *	Die roll function returns a random number that is between 1 and
 *	the numberOfSides.
 */
int Die::roll() {
    return (std::rand() % numberOfSides) + 1;
}

/**
 *	Returns the number of sides a Die has
 */
int Die::getNumberOfSides() const {
	return numberOfSides;
}