/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Option class provides validation checks and will
** reprompt the user when a user inputs an invalid choice.
*********************************************************************/
#ifndef	OPTION_HPP
#define OPTION_HPP

#include <iostream>
#include <algorithm>
#include <climits>		// INT_MAX
#include <cstddef>      // std::size_t    

class Option {
	private:
		std::string prompt;
		int min, max;
	public:
		Option(std::string, int, int);
		int getSelection();
		float getFloat();
};
#endif	// OPTION_HPP