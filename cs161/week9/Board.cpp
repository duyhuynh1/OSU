/*********************************************************************
** Author: Tony Huynh
** Date: 03/07/2018
** Description: Create a Board object that represents a Tic-Tac-Toe 
** board game. The default constructor initializes a 3x3 grid of 
** empty squares. The function makeMoves checks for valid moves and 
** the function gameState returns the game's current Status.
*********************************************************************/
#include "Board.hpp"
#include <iostream>

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
 *
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
	// Check if 'x' or 'o' won on a vertical line
	for (int i = 0; i < 3; i++) {
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
			if (grid[0][i] == markX) {
				return X_WON;
			} else if (grid[0][i] == markO) {
				return O_WON;
			}
		}
	}

	// Check if 'x' or 'o' won on a horizontal line
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			if (grid[i][0] == markX) {
				return X_WON;
			} else if (grid[i][0] == markO) {
				return O_WON;
			}
		}
	}

	// Check if 'x' or 'o' won on a diagonal line
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		if (grid[1][1] == markX) {
			return X_WON;
		} else if (grid[1][1] == markO) {
			return O_WON;
		}
	} else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		if (grid[1][1] == markX) {
			return X_WON;
		} else if (grid[1][1] == markO) {
			return O_WON;
		}
	}

	// Check for a DRAW. All squares should be occupied.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == markEmpty) {
				return UNFINISHED;
			}
		}
	}
	return DRAW;
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