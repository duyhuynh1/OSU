/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Barbarian class is a derived Character class. It 
** has attributes such as attack, defense, armor, strength, and no 
** special abilities.
*********************************************************************/
#include "Barbarian.hpp"

/**
 *  Barbarian class default constructor
 *  attack   = 2d6 {min: 2, max: 12}
 *  defense  = 2d6 {min: 2, max: 12}
 *  armor    = 0
 *  strength = 12
 */
Barbarian::Barbarian(const std::string name) : Character(name, "Barbarian", 0, 12) {
    initDice(2, 6, 2, 6);
}