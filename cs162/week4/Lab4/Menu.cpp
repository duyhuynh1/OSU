/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
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
 *  GetValue function returns the value selected by the user.
 *  @param index Is the index of the Option object in the selection vector.
 */
int Menu::getValue(int index) {
	return selection[index]->getSelection();
}