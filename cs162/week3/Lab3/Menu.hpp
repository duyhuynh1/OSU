#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>	// REMOVE
#include <vector>
#include "Option.hpp"

class Menu {
		std::vector<Option *> selection;
	public:
		void addOption(Option * ptrOption);
		int getValue(int index);
};
#endif	// MENU_HPP