/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: The Board Class provides the necessary functions and
** information for the Ant to navigate the grid.
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
	private:
		const char WHITE_SPACE = ' ';
		const char BLACK_SPACE = '#';
		const char ANT_SPACE = '*';
		int xLimit;
		int yLimit;
		char **grid = NULL;
	public:
		Board(int row, int col);
		~Board();
		void fill(int x, int y);
		bool isOutOfBound(int row, int col);
		void flipSpace(int x, int y, char value);
		char getSpaceValue(int x, int y);
		int getXLimit() const;
		int getYLimit() const;
		void show();
};
#endif	// BOARD_HPP