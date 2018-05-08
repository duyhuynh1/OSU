/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The character class is the base class for all other 
** types of characters in this combat game. Each characters has the
** following attributes such as attack, defense, armor, and strength.
*********************************************************************/
#include "Character.hpp"

Character::Character(int attack, int defense, int armor, int strength) {
	attackPoints = attack;
	defensePoints = defense;
	armorPoints = armor;
	strengthPoints = strength;
}

void Character::attack() {

}