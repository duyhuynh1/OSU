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

class Character {
	protected:
		std::string name = "";
		bool abilityActivated = false;
		int maxStrengthPoints;
		int totalDamage = 0;
		int attackPoints = 0;
		int defensePoints = 0;
		int armorPoints;
		int strengthPoints;
		std::string characterType;
		std::vector<Dice *> attackPowerDice;
		std::vector<Dice *> defensePowerDice;
		void initDice(int, int, int, int);
	public:
		Character(std::string, std::string, int, int);
		virtual ~Character();
		virtual void attack(Character *);
		virtual void defend(int &);
		bool isAlive();
		void getCharacterInfo() const;
		std::string getCharacterName() const;
		std::string getCharacterType() const;
		void recoverStrengthPoints();
		int getTotalDamage() const;
		int getAttackPoints() const;
		int getDefensePoints() const;
		int getArmorPoints() const;
		int getStrengthPoints() const;
		// int getMaxStrengthPoints() const;
};
#endif	// CHARACTER_HPP