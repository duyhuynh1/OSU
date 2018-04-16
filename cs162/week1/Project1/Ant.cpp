/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: The Ant class implementation. It provides the
** necessary functions for the ant to perform required actions based
** off of set rules.
*********************************************************************/
#include "Ant.hpp"

/**
 *	Ant constructor
 *	@param x An integer depicting the starting x coordinate
 *	@param y An integer depicting the starting y coordinate
 *	@param steps An integer depicting the number of steps available
 *	@param mBoard A Board Object the Ant will navigate on 
 */
Ant::Ant(int x, int y, int steps, Board *mBoard) {
	this->x = x;
	this->y = y;
	this->direction = WEST;
	this->steps = steps;
	boardPtr = mBoard;
}

/**
 *	Returns The Ant's current x-coordinate
 *	@return x coordinate of the Ant
 */
int Ant::getCurrentXPosition() const { return this->x; }

/**
 *	Returns the Ant's current y-coordinate
 *	@return y coordinate of the Ant
 */
int Ant::getCurrentYPosition() const { return this->y; }

/**
 *	Returns the Ant's current facing direction
 *	@return direction of the Ant.
 */
Direction Ant::getDirection() const { return this->direction; }

/**
 *	Returns the Ant's current amount of steps
 *	@return steps of the Ant
 */
int Ant::getSteps() const { return this->steps; }

/**
 *	Moves the Ant forward depending on it's location and direction
 *	If direction is NORTH then move forward by x - 1;
 *	If direction is SOUTH then move forward by x + 1;
 *	If direction is EAST then move forward by y + 1;
 *	If direction is WEST then move forward by y - 1;
 */
void Ant::moveForward() {
	int oldXCoord = getCurrentXPosition();
	int oldYCoord = getCurrentYPosition();
	char spaceValue = boardPtr->getSpaceValue(oldXCoord, oldYCoord);

	boardPtr->fill(oldXCoord, oldYCoord);
	std::cout << "Number of steps left: " << steps << std::endl;
	boardPtr->show();

	turn(getDirection(), spaceValue);

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

	if (boardPtr->isOutOfBound(getCurrentXPosition(), getCurrentYPosition())) {
		switch (getDirection()) {
			case NORTH:
				this->x = boardPtr->getXLimit();
				break;
			case SOUTH:
				this->x = 0;
				break;
			case EAST:
				this->y = 0;
				break;
			case WEST:
				this->y = boardPtr->getYLimit();
				break;
		}
	}

	boardPtr->flipSpace(oldXCoord, oldYCoord, spaceValue);
	this->steps -= 1;
}

/**
 *	Performs the turning operation depending on current direction 
 *	and space value
 *	@param direction The Direction the Ant is currently facing
 *	@param spaceValue The current space the Ant is occupying
 */
void Ant::turn(Direction direction, char spaceValue) {
	if (spaceValue == ' ') {
		switch (direction) {
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
		switch (direction) {
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
}