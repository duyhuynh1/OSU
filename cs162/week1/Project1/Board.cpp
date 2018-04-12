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
 *	@param x An integer depicting the number of xs
 *	@param y An integer depicting the number of yumns
 */
Board::Board(int x, int y) {
	yCoordOutOfBound = x;
	xCoordOutOfBound = y;

	grid = new char *[x];
	for (int i = 0; i < x; i++) {
		grid[i] = new char[y];
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			grid[i][j] = WHITE_SPACE;
		}
	}
}

/**
 *	Board destructor
 */
Board::~Board() {
	std::cout << "[D]: Inside ~Board() destructor" << std::endl;	// REMOVE
	// for (int i = 0; i < xCoordOutOfBound; i++) {
	// 	delete [] grid[i];
	// }
	// delete [] grid;
	// std::cout << "[D]: Board freed memory" << std::endl;	// REMOVE
	// // TODO: Delete all memory allocated to array
}

/**
 *	Validates the forward movement.
 *	@return TRUE if forward movement positions the Ant to an out of bound location.
 *	Otherwise FALSE if forward movement positions the Ant within the grid. 
 */
bool Board::isOutOfBound(int x, int y) {
	std::cout << "[D]: Inside Board::isOutOfBound()" << std::endl;	// REMOVE
	if (y > yCoordOutOfBound || x > xCoordOutOfBound) {
		return true;
	} else {
		return false;
	}
}

/**
 *	Maybe should be private
 */
char Board::getSpaceValue(int x, int y) {
	return grid[x][y];
}

/**
 *	Space Fill logic
 */
void Board::fill(int &x, int &y) {
	if (!isOutOfBound(x, y)) {
		std::cout << "[D]: move to location is valid" << std::endl;	// REMOVE
		grid[x][y] = ANT_SPACE;
	}
	// Check where 
}

/**
 *	Display the current Board. The Ant's current position should be passed here
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