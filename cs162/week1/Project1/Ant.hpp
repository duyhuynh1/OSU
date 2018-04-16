/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: The Ant class provides all the functionality needed 
** to navigate the board. Direction allows the Ant to store it's
** current orientation.
*********************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

enum Direction { NORTH, SOUTH, EAST, WEST };

class Ant {
	private:
		int x;
		int y;
		Direction direction;
		int steps;
		Board *boardPtr = NULL;
		int getCurrentXPosition() const;
		int getCurrentYPosition() const;
		Direction getDirection() const;
		void turn(Direction direction, char spaceValue);
	public:
		Ant(int x, int y, int steps, Board *mBoard);
		int getSteps() const;
		void moveForward();
};
#endif	// ANT_HPP