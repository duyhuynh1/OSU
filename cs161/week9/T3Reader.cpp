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
	std::ifstream inputFile;

	inputFile.open(filename);
	if (inputFile) {
		// Sucessfully opened game file
		while (inputFile >> xCord >> yCord) {
			// Check if move is valid
			if (board.makeMove(xCord, yCord, currentPlayer)) {
				
				// Check the current game Status
				switch (board.gameState()) {
					// [NOTE]: GROUP THESE CASES TOGETHER!!!
					case X_WON:
						std::cout << "case: X_WON" << std::endl;
						inputFile.close();
						return true;
					case O_WON:
						std::cout << "case: O_WON" << std::endl;
						inputFile.close();
						return true;
					case DRAW:
						std::cout << "case: DRAW" << std::endl;
						inputFile.close();
						return true;
					case UNFINISHED:
						std::cout << "case: UNFINISHED" << std::endl;
						break;
				}
			} else {
				return false;	// Invalid move, square is already occupied
			}
			std::cout << "switching players" << std::endl;
			switchCurrentPlayer(currentPlayer);
		}
		return false;
	} else {
		return false;	// Failed to open filename
	}
}