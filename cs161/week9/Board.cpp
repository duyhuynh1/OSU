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
 *	Returns the game's current Status. Scan's the grid to see if a player has won
 *
 *	@return Status enum representing the various game status:
 *	X_WON, O_WON, DRAW, UNFINISHED
 */
Status Board::gameState() {
	printBoard();	// REMOVE

	// TODO: Fix bug with markEmpty trigerring X_WON/O_WON enum Status
	// Check if 'x' or 'o' won on a vertical line
	std::cout << "Board::gameState() checking vertical line" << std::endl;	// REMOVE
	for (int i = 0; i < 3; i++) {
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
			if (grid[0][i] == markX) {
				std::cout << "return: X_WON" << std::endl;	// REMOVE
				return X_WON;
			} else if (grid[0][i] == markO) {
				std::cout << "return: O_WON" << std::endl;	// REMOVE
				return O_WON;
			}
		}
	}

	// Check if 'x' or 'o' won on a horizontal line
	std::cout << "Board::gameState() checking horizontal line" << std::endl;	// REMOVE
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			if (grid[i][0] == markX) {
				std::cout << "return: X_WON" << std::endl;	// REMOVE
				return X_WON;
			} else if (grid[i][0] == markO) {
				std::cout << "return: O_WON" << std::endl;	// REMOVE
				return O_WON;
			}
		}
	}

	// Check if 'x' or 'o' won on a diagonal line
	std::cout << "Board::gameState() checking diagonal line" << std::endl;	// REMOVE
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		if (grid[1][1] == markX) {
			std::cout << "return: X_WON" << std::endl;	// REMOVE
			return X_WON;
		} else if (grid[1][1] == markO) {
			std::cout << "return: O_WON" << std::endl;	// REMOVE
			return O_WON;
		}
	} else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		if (grid[1][1] == markX) {
			std::cout << "return: X_WON" << std::endl;
			return X_WON;
		} else if (grid[1][1] == markO) {
			std::cout << "return: O_WON" << std::endl;
			return O_WON;
		}
	}

	// Check for a DRAW. All squares should be occupied.
	// x = 120, o = 111
	std::cout << "Board::gameState() checking DRAW or UNFINISHED" << std::endl;	// REMOVE
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			sum += static_cast<int>(grid[i][j]);
		}
	}
	if (sum == 1044 || sum == 1035) {
		return DRAW;
	} else {
		return UNFINISHED;
	}
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
	std::cout << "\t+---+---+---+" << std::endl;
	std::cout << "\t| " << grid[1][0] << " |"
			  << " " << grid[1][1] << " |"
			  << " " << grid[1][2] << " |" << std::endl;
	// Row 2, Col 0-2
	std::cout << "\t+---+---+---+" << std::endl;
	std::cout << "\t| " << grid[2][0] << " |"
			  << " " << grid[2][1] << " |"
			  << " " << grid[2][2] << " |" << std::endl;
}