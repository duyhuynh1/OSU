/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: This class represents a tic-tac-toe board. It has 
** constructors that 
*********************************************************************/
#ifndef T3READER_HPP
#define T3READER_HPP

#include <string>
#include <fstream>	// REMOVE
#include <iostream>	// REMOVE ME before submit
#include "Board.hpp"

class T3Reader {
	private:
		Board game;
		char currentPlayer;
		void switchCurrentPlayer(char &);
	public:
		T3Reader(char);					// Default Constructor
		bool readGameFile(const std::string);	// Read specified game file


};
#endif	// T3READER_HPP