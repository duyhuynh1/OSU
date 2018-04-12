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
		bool isOutOfBound(int row, int col);
	public:
		Board(int row, int col);	// TODO: Need to prevent people from modifying
		~Board();					// TODO: Destructor to clear grid object
		void fill(int &x, int &y);	// TODO: The board will receive 2 args for space to fill
		char getSpaceValue(int x, int y);
		void show();

									// TODO: The board will have logic to switch the space appropriately
};
#endif	// BOARD_HPP