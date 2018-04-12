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
int Ant::getCurrentXPosition() {
	return this->x;
}

/**
 *	@return 
 */
int Ant::getCurrentYPosition() {
	return this->y;
}

/**
 *	@return
 */
Direction Ant::getDirection() {
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
 *	If direction is NORTH then move forward by x - 1;
 *	If direction is SOUTH then move forward by x + 1;
 *	If direction is EAST then move forward by y + 1;
 *	If direction is WEST then move forward by y - 1;
 */
void Ant::moveForward() {
	int oldXCoord = getCurrentXPosition();
	int oldYCoord = getCurrentYPosition();
	std::cout << "[D]: oldXCoord = " << oldXCoord		// REMOVE
			  << "; oldYCoord = " << oldYCoord << std::endl;	// REMOVE
	char spaceValue = boardPtr->getSpaceValue(oldXCoord, oldYCoord);
	std::cout << "[D]: oldSpaceValue = " << spaceValue << std::endl;	// REMOVE

	boardPtr->fill(oldXCoord, oldYCoord);
	boardPtr->show();
	// TODO: Simplify algorithm
	if (spaceValue == ' ') {
		std::cout << "[D]: spaceValue == \' \' is TRUE" << std::endl;	// REMOVE
		std::cout << "[D]: current direction = " << getDirection() << std::endl;	// REMOVE
		switch (getDirection()) {
			case NORTH:
				this->direction = EAST;
				break;
			case SOUTH:
				this->direction = WEST;
				break;
			case EAST:
				this->direction = SOUTH;
				break;
			case WEST:
				this->direction = NORTH;
				break;
		}
	} else {
		std::cout << "[D]: spaceValue == \'#\'" << std::endl;	// REMOVE
		switch (getDirection()) {
			case NORTH:
				this->direction = WEST;
				break;
			case SOUTH:
				this->direction = EAST;
				break;
			case EAST:
				this->direction = NORTH;
				break;
			case WEST:
				this->direction = SOUTH;
				break;
		}
	}
	std::cout << "[D]: change direction to " << getDirection() << std::endl;	// REMOVE

	// Moving forward
	std::cout << "[D]: Moving forward..." << std::endl;	// REMOVE
	switch (getDirection()) {
		case NORTH:
			this->x = getCurrentXPosition() - 1;
			break;
		case SOUTH:
			this->x = getCurrentXPosition() + 1;
			break;
		case EAST:
			this->y = getCurrentYPosition() + 1;
			break;
		case WEST:
			this->y = getCurrentYPosition() - 1;
			break;
	}

	// Corner case handled OPTION#2 make the ant wrap around
	if (boardPtr->isOutOfBound(getCurrentXPosition(), getCurrentYPosition())) {
		std::cout << "corner case" << std::endl;	// REMOVE
		if (getCurrentXPosition() < 0 || getCurrentXPosition() > boardPtr->getXLimit()) {
			this->x = boardPtr->getXLimit();
		} else if (getCurrentYPosition() < 0 || getCurrentYPosition() > boardPtr->getYLimit()) {
			this->y = boardPtr->getYLimit();
		}
		boardPtr->fill(getCurrentXPosition(), getCurrentYPosition());
	}

	std::cout << "[D]: Flipping old X and Y coordinates" << std::endl;	// REMOVE
	boardPtr->flipSpace(oldXCoord, oldYCoord, spaceValue);

	std::cout << "[D]: Ant moved to newXCoord = " << getCurrentXPosition()
			  << "; newYCoord = " << getCurrentYPosition() << std::endl;	// REMOVE

	this->steps -= 1;
	std::cout << "[D]: number of steps left = " << getSteps();
}

void Ant::showInfo() {
	std::cout << "Ant: {"
			  << "\n\tx = " << getCurrentYPosition()
			  << "\n\ty = " << getCurrentYPosition()
			  << "\n\tdirection = " << getDirection()
			  << "\n\tsteps = " << getSteps()
			  << "\n};" << std::endl;
}