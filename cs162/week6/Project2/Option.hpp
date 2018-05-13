/*********************************************************************
** Program name: Recursive Functions
** Author: Tony Huynh
** Date: 5/6/2018
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
		std::string value;
	public:
		
		Option(std::string);
		Option(std::string, int, int);
		std::string getString();
		int getUnsignedInteger();
		float getUnsignedFloat();
};
#endif	// OPTION_HPP