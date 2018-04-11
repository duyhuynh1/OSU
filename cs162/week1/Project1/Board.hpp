/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board {
	private:
		const char WHITE_SPACE = ' ';
		const char BLACK_SPACE = '#';
		const char ANT_SPACE = '*';
		int xCoordOutOfBound;
		int yCoordOutOfBound;
		char **grid = NULL;
	public:
		Board(int row, int col);	// TODO: Need to prevent people from modifying
		bool isOutOfBound(int row, int col);
		void show();
};
#endif	// BOARD_HPP