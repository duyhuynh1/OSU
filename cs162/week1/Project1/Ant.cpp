/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
*********************************************************************/
#include "Ant.hpp"

/**
 *	Ant constructor
 */
Ant::Ant(int x, int y) {
	std::cout << "[D]: Inside Ant constructor()" << std::endl;	// REMOVE
	setPosition(x, y);
	std::cout << "[D]: Setting default direction to NORTH" << std::endl;	// REMOVE
	setDirection(0);
}

/**
 *	Set the Ant's position
 */
void Ant::setPosition(int x, int y) {
	// TODO: Need to check if position is going to be out of bound
	// TODO: Need to check the Ant's current Facing
	std::cout << "[D]: Inside Ant::setPosition()" << std::endl;	// REMOVE
	this->x = x;
	this->y = y;
	std::cout << "[D]: set Ant's position x = " << this->x << "; y = " << this->y << std::endl;	// REMOVE
}

/**
 *	Set the Ant's cardinal direction
 */
void Ant::setDirection(int choice) {
	std::cout << "[D]: Inside Ant::setDirection()" << std::endl;	// REMOVE
	switch (choice) {
		case 0:
			std::cout << "[D]: Direction is set to NORTH" << std::endl;	// REMOVE
			this->direction = NORTH;
			break;
		case 1:
			std::cout << "[D]: Direction is set to SOUTH" << std::endl;	// REMOVE
			this->direction = SOUTH;
			break;
		case 2:
			std::cout << "[D]: Direction is set to EAST" << std::endl;	// REMOVE
			this->direction = EAST;
			break;
		case 3:
			std::cout << "[D]: Direction is set to WEST" << std::endl;	// REMOVE
			this->direction = WEST;
			break;
	}
}

/**
 *	@return 
 */
int Ant::getCurrentXPosition() const {
	return this->x;
}

/**
 *	@return 
 */
int Ant::getCurrentYPosition() const {
	return this->y;
}

/**
 *	@return
 */
Direction Ant::getDirection() const {
	return this->direction;
}