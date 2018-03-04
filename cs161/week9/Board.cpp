/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Create a Board object that represents a Tic-Tac-Toe board
** game. 
*********************************************************************/
#include "Board.hpp"
#include <iostream>	// REMOVE ME before submit

/**
 *	Default Board constructor
 *  Initializes the 3x3 array with the space character ' '.
 */

Board::Board() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = markEmpty;
		}
	}
}

/**
 *	Validates the user's attempt to move to the grid position.
 *	@param row x-coordinates (row)
 *	@param col y-coordinates (column)
 *	@param marker
 *	@return true If the location is unoccupied, otherwise false
 */
bool Board::makeMove(int row, int col, char mark) {
	// Check if position is unoccupied e.g an empty square ' '
	if (grid[row][col] == markEmpty) {
		grid[row][col] = mark;
		return true;
	} else {
		return false;
	}
}

/**
 *	Returns the game's current status
 */
Status Board::gameState() {
	return X_WON;
}

/**
 *	Prints out the current board, displaying the current moves made.
 *	Used for debugging.
 */
void Board::printBoard() {
	// Row 0, Col 0-2
	std::cout << "\t| " << grid[0][0] << " |"
			  << " " << grid[0][1] << " |"
			  << " " << grid[0][2] << " |" << std::endl;
	// Row 1, Col 0-2
	std::cout << "\t-------------" << std::endl;
	std::cout << "\t| " << grid[1][0] << " |"
			  << " " << grid[1][1] << " |"
			  << " " << grid[1][2] << " |" << std::endl;
	// Row 2, Col 0-2
	std::cout << "\t-------------" << std::endl;
	std::cout << "\t| " << grid[2][0] << " |"
			  << " " << grid[2][1] << " |"
			  << " " << grid[2][2] << " |" << std::endl;
}