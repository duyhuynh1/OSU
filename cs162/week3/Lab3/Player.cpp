/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Player Class has all the functions that replicate
** how a Player who play the Dice War Game. It provides information
** about the Player and the Dice object the Player has.
*********************************************************************/
#include "Player.hpp"

/**
 *	Player default constructor
 *	@param name The Player's name
 *	@param ptrDie A pointer to a Die object
 *	@param type The Type of Die the player has
 */
Player::Player(std::string name, Die * ptrDie, DieType type) {
    // std::cout << "Player constructor called" << std::endl;  // REMOVE
    this->name = name;
    this->ptrDie = ptrDie;
    this->type = type;
}

/**
 *  Return's the player's name
 */
std::string Player::getName() const {
    return name;
}

/**
 *  Return's the Player's dice roll value
 */
int Player::rollDie() {
    return ptrDie->roll();
}

/**
 *	Adds a point to the Player
 */
void Player::addPoints() {
	points += 1;
}

/**
 *	Returns the Player's points
 */
int Player::getPoints() const {
	return points;
}

/**
 *	Returns the Player's DieType
 */
std::string Player::getDieType() const {
	switch (type) {
		case NORMAL_DIE:
			return "NORMAL_DIE";
			break;
		case LOADED_DIE:
			return "LOADED_DIE";
			break;
	}
}

/**
 *	Returns the Player's Die amount of sides
 */
int Player::getDieNumberOfSides() const {
	return ptrDie->getNumberOfSides();
}