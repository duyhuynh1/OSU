/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: This class represents a tic-tac-toe board. It has 
** constructors that 
*********************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

enum Status { X_WON, O_WON, DRAW, UNFINISHED };

class Board {
	private:
		char grid[3][3];				// 3x3 array representing board.
		const char markX = 'x';			// represents a square marked 'x' 
		const char markO = 'o';			// represents a square marked 'o'
		const char markEmpty = ' ';		// represents an empty square ' '
		// Need private function to handle checking status of game?
	public:
		Board();						// Default Constructor
		bool makeMove(int, int, char);	// Allows the user to mark a location
		Status gameState();				// Returns the game's current status
		void printBoard();				// Display's current board
};
#endif	// BOARD_HPP