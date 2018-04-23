/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Loaded Die class is a derived class of the Die 
** Class. It's roll function has a higher probability of returning
** a larger number.
*********************************************************************/
#include "Die.hpp"
#include "LoadedDie.hpp"

/**
 *  Loaded Die constructor inherits properties from the Die Class
 *  @param side An interger depicting the number of sides the Die has
 */
LoadedDie::LoadedDie(int side) : Die(side) {
    this->numberOfSides = side;
}

/**
 *  With a Loaded Die the user is able to roll the Die twice.
 *  The roll with the greater value will be kept.
 */
int LoadedDie::roll() {
    int firstRollValue = (rand() % numberOfSides) + 1;
    int secondRollValue = (rand() % numberOfSides) + 1;
    if (firstRollValue == secondRollValue) {
        return firstRollValue;
    } else if (firstRollValue > secondRollValue) {
        return firstRollValue;
    } else if (firstRollValue < secondRollValue) {
        return secondRollValue;
    }
}