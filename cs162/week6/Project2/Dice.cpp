/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Dice class is the base class that provides all
** the necessary properties to create a Dice object. It stores the
** number of sides and the roll function simulats a dice roll.
*********************************************************************/
#include "Dice.hpp"

/**
 *  Dice constructor
 */
Dice::Dice(int side) {
    numberOfSides = side;
    std::srand(std::time(0));
}

// *
//  *	Dice default destructor
 
// Dice::~Dice() { } // REMOVE

/**
 *	Dice roll function returns a random number that is between 1 and
 *	the numberOfSides.
 */
int Dice::roll() {
    return (std::rand() % numberOfSides) + 1;
}

/**
 *	Returns the number of sides a Dice has
 */
int Dice::getNumberOfSides() const {
	return numberOfSides;
}