/*********************************************************************
** Author: Tony Huynh
** Date: 03/07/2018
** Description: Create a Board object that represents a Tic-Tac-Toe 
** board game. Provides a function called readGameFile used to
** validate a Tic-Tac-Toe game. Helper function switchCurrentPlayer
** is used to swap the current player.
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
}

/**
 *	Switches the current player
 *
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
 *	Returns the game file validity.
 *	
 *	@param filename The game file that will be read
 *	@return false if any of the moves is for a square that was
 *	already occupied, or if there are still additional moves in the 
 *	file after the game has finished, otherwise true
 */
bool T3Reader::readGameFile(const std::string filename) {
	int xCord = 0;
	int yCord = 0;
	bool finished = false;
	std::ifstream inputFile;

	inputFile.open(filename);
	if (inputFile) {									// Check if open succeed
		while (inputFile >> xCord >> yCord) {			// Read file values
			if (!finished) {
				// Check if move is valid
				if (board.makeMove(xCord, yCord, currentPlayer)) {
					switch (board.gameState()) {
						case X_WON:
						case O_WON:
						case DRAW:
							finished = true;			// Game is finished
							break;
						case UNFINISHED:
							break;
					}
				} else {
					inputFile.close();
					return false;						// Move is invalid
				}
				switchCurrentPlayer(currentPlayer);		// Helper function
			} else {
				inputFile.close(); 
				return false;
			}
		}
		inputFile.close();
		return true;									// Completed reading file
	} else {
		return false;									// Failed to open file
	}
}