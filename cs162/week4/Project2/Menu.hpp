/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Option class provides validation checks and will
** reprompt the user when a user inputs an invalid choice.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>	// REMOVE
#include <vector>
#include "Option.hpp"

class Menu {
		std::vector<Option *> selection;
	public:
		void addOption(Option * ptrOption);
		void removeOption(int index);
		int getValue(int index);
};
#endif	// MENU_HPP