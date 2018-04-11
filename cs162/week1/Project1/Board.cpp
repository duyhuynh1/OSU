/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: The Board class provides the grid in which the Ant
** can navigate.
*********************************************************************/
#include "Board.hpp"

/**
 *	Board constructor 
 *	@param row An integer depicting the number of rows
 *	@param col An integer depicting the number of columns
 */
Board::Board(int row, int col) {
	yCoordOutOfBound = row;
	xCoordOutOfBound = col;

	grid = new char *[row];
	for (int i = 0; i < row; i++) {
		grid[i] = new char[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			grid[i][j] = WHITE_SPACE;
		}
	}
}

/**
 *	Return ???
 *	@return TRUE if forward movement positions the Ant to an out of bound location.
 *	Otherwise FALSE if forward movement positions the Ant within the grid. 
 */
bool Board::isOutOfBound(int row, int col) {
	std::cout << "[D]: Inside Board::isOutOfBound()" << std::endl;	// REMOVE
	if (row > yCoordOutOfBound || col > xCoordOutOfBound) {
		return true;
	} else {
		return false;
	}
}

/**
 *	Display the current Board
 */
void Board::show() {
	std::cout << "[D]: Inside Board::show()" << std::endl;	// REMOVE
	for (int i = 0; i < xCoordOutOfBound; i++) {
		for (int j = 0; j < yCoordOutOfBound; j++) {
			std::cout << "|" << grid[i][j];
		}
		std::cout << "|\n";
	}
}