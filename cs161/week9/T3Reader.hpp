/*********************************************************************
** Author: Tony Huynh
** Date: 3/07/2018
** Description: This class represents a tic-tac-toe board. It has 
** constructors that specifies the player with the first move. Also
** provided is a function to read game files.
*********************************************************************/
#ifndef T3READER_HPP
#define T3READER_HPP

#include <string>
#include <fstream>
#include "Board.hpp"

class T3Reader {
	private:
		Board board;
		char currentPlayer;
		void switchCurrentPlayer(char &);
	public:
		T3Reader(char);					// Default Constructor
		bool readGameFile(const std::string);	// Read specified game file
};
#endif	// T3READER_HPP