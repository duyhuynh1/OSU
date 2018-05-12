/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The character class is the base class for all other 
** types of characters in this combat game. It provides the characters
** with atrributes such as attack, defense, armor, and strength.
*********************************************************************/
#ifndef	BARBARIAN_HPP
#define	BARBARIAN_HPP

#include "Character.hpp"

class Barbarian : public Character {
	public:
        Barbarian();
};
#endif	// BARBARIAN_HPP