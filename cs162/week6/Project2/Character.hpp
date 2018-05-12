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

#include <iostream>
#include <vector>
#include "Dice.hpp"

enum SpecialAbilities { NONE, CHARM, MOB, GLARE, HOGWARTS };	// Even needed??

class Character {
	protected:
		int turns = 0;
		int attackPoints = 0;
		int defensePoints = 0;
		int armorPoints;
		int strengthPoints;
		std::string characterType;
		// std::string characteristics = "";
		SpecialAbilities characterAbility;
		// virtual void defend();
		std::vector<Dice *> attackPowerDice;
		std::vector<Dice *> defensePowerDice;
	public:
		Character(std::string, SpecialAbilities, int, int);	// Do we even need SpecialAbilities
		void initDice(int, int, int, int);	// Should this be protected?
		virtual ~Character();
		virtual void attack(Character *);
		virtual void defend(int &);	// Should be private???
		bool isAlive();
		std::string getCharacterType() const;
		int getArmorPoints() const;
		int getStrengthPoints() const;
};
#endif	// CHARACTER_HPP