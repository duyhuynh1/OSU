/*********************************************************************
** Program name: Recursive Functions
** Author: Tony Huynh
** Date: 5/6/2018
** Description: The Menu Class creates a structure for easy menu 
** selections. This class can be reused by other programs.
*********************************************************************/
#include "Menu.hpp"

/**
 *  Add option appends an Option object to the selection vector.
 *  @param ptrOption is a pointer to an Option object
 */
void Menu::addOption(Option * ptrOption) {
	selection.push_back(ptrOption);
}

/**
 *	Remove option starting from the back of the selection vector.
 */
void Menu::removeOption(int index) {
	selection.erase(selection.begin() + index);
}

/**
 *  GetValue function returns the value selected by the user.
 *  @param index Is the index of the Option object in the selection vector.
 */
int Menu::getUnsignedInteger(int index) {
	return selection[index]->getUnsignedInteger();
}

/**
 *	Menu getString value function returns a valid non-empty string
 *	input.
 */
std::string Menu::getString(int index) {
	return selection[index]->getString();
}