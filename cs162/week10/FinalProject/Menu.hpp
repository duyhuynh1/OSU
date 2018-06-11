/*********************************************************************
** Program name: Recursive Functions
** Author: Tony Huynh
** Date: 5/6/2018
** Description: The Option class provides validation checks and will
** reprompt the user when a user inputs an invalid choice.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>	// REMOVE
#include <vector>
#include "Option.hpp"

class Menu {
		// std::vector<Option *> selection;
        std::vector<Option> selection;
	public:
		// void addOption(Option * ptrOption);
		void removeOption(int index);
		int getUnsignedInteger(int index);
		std::string getString(int index);
        void addOption(Option &option);
};
#endif	// MENU_HPP