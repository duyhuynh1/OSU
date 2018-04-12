/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
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
	public:
		Ant(int x, int y, int steps, Board mBoard);
		~Ant();
		int getCurrentXPosition();
		int getCurrentYPosition();
		Direction getDirection();
		int getSteps() const;
		void moveForward();
		void showInfo();					// TODO: This can be replaced with a helper
};
#endif	// ANT_HPP