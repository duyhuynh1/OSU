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
		Board *boardPtr = NULL;
		Direction direction;
		int x;
		int y;
		void setPosition(int x, int y);
		void setDirection(int choice);	// Set from menu options???
	public:
		Ant(int x, int y);
		int getCurrentXPosition() const;
		int getCurrentYPosition() const;
		Direction getDirection() const;

};
#endif	// ANT_HPP