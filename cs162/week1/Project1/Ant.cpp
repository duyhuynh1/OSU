/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
*********************************************************************/
#include "Ant.hpp"

/**
 *	Ant constructor
 *	@param x An integer depicting the starting x coordinate
 *	@param y An integer depicting the starting y coordinate
 *	@param numStep, 
 */
Ant::Ant(int x, int y, int steps, Board mBoard) {
	std::cout << "[D]: Inside Ant constructor()" << std::endl;	// REMOVE
	this->x = x;
	this->y = y;
	this->direction = WEST;			// Default direction in wikipedia
	this->steps = steps;
	boardPtr = &mBoard;
}

/**
 *	Ant destructor
 */
Ant::~Ant() {
	std::cout << "[D]: Inside ~Ant() destructor" << std::endl;	// REMOVE
	// delete [] boardPtr;
	// std::cout << "[D]: Ant freed memory" << std::endl;	// REMOVE
}

/**
 *	@return An integer depicting the Ant's current x coordinate
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

/**
 *
 */
int Ant::getSteps() const {
	return this->steps;
}

/**
 *	Moves the Ant forward depending on it's location and direction.
 *	If direction is NORTH then move forward by y - 1;
 *	If direction is SOUTH then move forward by y + 1;
 *	If direction is EAST then move forward by x + 1;
 *	If direction is WEST then move forward by x - 1;
 */
void Ant::moveForward() {
	std::cout << "[D]: Inside Ant::moveForward()" << std::endl;	// REMOVE
	int moveX;
	int moveY;
	char currentOccupiedSpace = boardPtr->getSpaceValue(getCurrentXPosition(), getCurrentYPosition());
	// 1 - Need to check the space the Ant is currently occupying
	std::cout << "[D]: The Ant is occupying a \'"
			  << currentOccupiedSpace << "\' space " << std::endl;

	if (currentOccupiedSpace == '#') {
		std::cout << "[D]: BLACK_SPACE" << std::endl;
	} else {
		std::cout << "[D]: WHITE_SPACE" << std::endl;
	}
	// if (boardPtr->getSpaceValue(getCurrentXPosition(), getCurrentYPosition()) {

	// }

	// switch (this->direction) {
	// 	case NORTH:
	// 		moveY = getCurrentYPosition() - 1;
	// 		// setPosition(getCurrentXPosition(), moveY);
	// 		break;
	// 	case SOUTH:
	// 		moveY = getCurrentYPosition() + 1;
	// 		// setPosition(getCurrentXPosition(), moveY);
	// 		break;
	// 	case EAST:
	// 		moveX = getCurrentXPosition() + 1;
	// 		// setPosition(moveX, getCurrentYPosition());
	// 		break;
	// 	case WEST:
	// 		moveX = getCurrentXPosition() - 1;
	// 		// setPosition(moveX, getCurrentYPosition()); 
	// 		break;
	// }
	this->steps -= 1;
}

void Ant::showInfo() {
	std::cout << "Ant: {"
			  << "\n\tx = " << getCurrentYPosition()
			  << "\n\ty = " << getCurrentYPosition()
			  << "\n\tdirection = " << getDirection()
			  << "\n\tsteps = " << getSteps()
			  << "\n};" << std::endl;
}