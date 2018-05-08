/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The character class is the base class for all other 
** types of characters in this combat game. It provides the characters
** with atrributes such as attack, defense, armor, and strength.
*********************************************************************/
#ifndef	CHARACTER_HPP
#define CHARACTER_HPP

enum SpecialAbilities { NONE, CHARM, MOB, GLARE, HOGWARTS };

class Character {
	private:
		int attackPoints;
		int defensePoints;
		int armorPoints;
		int strengthPoints;
		// std::string characteristics = "";
		SpecialAbilities abilities;
		// virtual void defend();
	public:
		Character(int, int, int, int);
		virtual void attack();
};
#endif	// CHARACTER_HPP