/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Create a Board object that represents a Tic-Tac-Toe 
** board game. 
*********************************************************************/
#include "T3Reader.hpp"

/**
 *	Default constructor specifies whether 'x' or 'o' should have
 *	the first move.
 *
 *	@param marker specfies whether char 'x' or 'o' has the first move
 */
T3Reader::T3Reader(char marker) {
	currentPlayer = marker;
	std::cout << "starting player: " << currentPlayer << std::endl;	// REMOVE ME
}

/**
 *	Switches the current player
 *	@param player The current player 
 */
void T3Reader::switchCurrentPlayer(char &player) {
	if (player == 'x') {
		player = 'o';
	} else {
		player = 'x';
	}
}

/**
 *	Returns the status of the game
 *	
 *	@param filename The game file that will be read
 *	@return false if any of the moves is for a square that was
 *	already occupied, or if there are still additional moves in the 
 *	file after the game has finished, otherwise true
 */
bool T3Reader::readGameFile(const std::string filename) {
	int xCord = 0;
	int yCord = 0;
	bool done = false;
	std::ifstream inputFile;

	inputFile.open(filename);
	if (inputFile) {
		while (inputFile >> xCord >> yCord) {
			std::cout << "\nplayer: " << currentPlayer;	// REMOVE ME
			std::cout << "; row: " << xCord;			// REMOVE ME
			std::cout << ", col: " << yCord;			// REMOVE ME
			game.makeMove(xCord, yCord, currentPlayer);
			std::cout << "; Status: " << game.gameState() << std::endl;	// REMOVE ME
			game.printBoard();
			switchCurrentPlayer(currentPlayer);
		}
		return done;
	}
	inputFile.close();
	return done = true;
}