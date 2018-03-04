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
 *	Check if a player has won the game
 *	@return a coded integer indicating the player who has won and 
 *	how they won
 */
char Board::gameVictory() {
	std::cout << "inside Board::gameVictory()" << std::endl;	// REMOVE

	// Check if 'x' or 'o' won on a vertical line
	for (int i = 0; i < 3; i++) {
		std::cout << "Checking col#" << i << std::endl;	// REMOVE
		if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) {
			return grid[0][i];
		}
	}

	// Check if 'x' or 'o' won on a horizontal line
	for (int i = 0; i < 3; i++) {
		std::cout << "Checking row#" << i << std::endl;	// REMOVE
		if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
			return grid[i][0];
		}
	}

	// Check if 'x' or 'o' won on a diagonal line
	std::cout << "Checking diagonal win" s<< std::endl;	// REMOVE
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
		return grid[1][1];
	} else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
		return grid[1][1];
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
 *	Returns the game's current Status
 *	@return Status enum representing the various game status:
 *	X_WON, O_WON, DRAW, UNFINISHED
 */
Status Board::gameState() {
	static int numberOfMoves = 1;

	std::cout << "number of moves: " << numberOfMoves; 	// REMOVE
	// Check if game is UNFINISHED
	if (numberOfMoves < 5) {
		numberOfMoves++;
		return UNFINISHED;
	}

	switch (numberOfMoves) {
		case 5:
		case 6:
		case 7:
		case 8:
			numberOfMoves++;
			if (gameVictory() == 'x') {
				return X_WON;
			} else if (gameVictory() == 'o'){
				return O_WON;
			}
			break;
		case 9:
			return DRAW;
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