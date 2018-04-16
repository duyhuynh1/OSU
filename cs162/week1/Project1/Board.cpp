/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: The Board class provides the grid in which the Ant
** can navigate. Information includes the space values of the grid.
*********************************************************************/
#include "Board.hpp"

/**
 *	Board constructor 
 *	@param x An integer depicting the number of rows
 *	@param y An integer depicting the number of columns
 */
Board::Board(int x, int y) {
	xLimit = x;
	yLimit = y;

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
	for (int i = 0; i < xLimit ; i++) {
		delete [] grid[i];
	}
	delete [] grid;
}

/**
 *	Validates the forward movement.
 *	@return TRUE if forward movement positions the Ant to an out of bound location.
 *	Otherwise FALSE if forward movement positions the Ant within the grid. 
 */
bool Board::isOutOfBound(int x, int y) {
	if ((x < 0 || x > getXLimit()) || (y < 0 || y > getYLimit())) {
		return true;
	} else {
		return false;
	}
}

/**
 *	@param x An integer depicting the grid's x-coordinate
 *	@param y An integer depicting the grid's y-coordinate
 */
char Board::getSpaceValue(int x, int y) {
	return grid[x][y];
}

/**
 *	Stores the Ant's current position on the grid
 *	@param x An integer depicting the Ant's x-coordinates
 *	@param y An integer depicting the Ant's y-coordinates
 */
void Board::fill(int x, int y) {
	grid[x][y] = ANT_SPACE;
}

/**
 *	Flip the previous space the Ant was occupying. If ' ' then
 *	flip to #. If # then flip to ' '.
 *	@param x An integer depicting the Ant's previous x-coordinate
 *	@param y An integer depicting the Ant's previous y-coordinate
 *	@param value A character representing the value of the
 *	previous square the Ant was occupying
 */
void Board::flipSpace(int x, int y, char value) {
	if (value == ' ') {
		grid[x][y] = BLACK_SPACE;
	} else {
		grid[x][y] = WHITE_SPACE;
	}
}

/**
 *	Returns the 'x' coordinate upper_limit
 *	@return xLimit The grid's maximum x-coordinate
 */
int Board::getXLimit() const {
	return this->xLimit - 1;
}

/**
 *	Return the 'y' coordinate upper_limit
 *	@return yLimit The grid's maximum y-coordinate
 */
int Board::getYLimit() const {
	return this->yLimit - 1;
}

/**
 *	Display the current Board.
 */
void Board::show() {
	for (int i = 0; i < xLimit; i++) {
		for (int j = 0; j < yLimit; j++) {
			std::cout << "|" << grid[i][j];
		}
		std::cout << "|\n";
	}
}