/*********************************************************************
** Program name: Doubly-Linked List
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The driver program that allows users to generate a
** linked list storing integer values.
*********************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"
#include "DoublyLinkedList.hpp"

int main() {
	DoublyLinkedList list;

	std::string mainMenuPrompt = "0. Exit\n"
								 "1. Add a new node to the head.\n"
								 "2. Add a new node to the tail.\n"
								 "3. Delete the first node in the list.\n"
								 "4. Delete the last node in the list.\n"
								 "5. Traverse the list reversely.\n"
								 "6. Travers the list.\n"
								 "=> ";
	std::string getIntegerPrompt = "Please enter an integer: ";
	Option *mainOptions = new Option(mainMenuPrompt, 0, 6);
	Option *getIntegerOption = new Option(getIntegerPrompt, INT_MIN, INT_MAX);
	Menu mMenu;
	mMenu.addOption(mainOptions);		// Index 0
	mMenu.addOption(getIntegerOption);	// Index 1

	bool exit = false;
	std::cout << std::string(50, '=') << std::endl;
	std::cout << "Welcome to my Doubly-Linked List!\n";
	std::cout << std::string(50, '=') << std::endl;
	do {
		switch (mMenu.getUnsignedInteger(0)) {
			case 0:
				exit = true;
				std::cout << ">>> Exit Program <<<" << std::endl;
				break;
			case 1:
				list.add(mMenu.getSignedInteger(1), HEAD);
				list.printList(HEAD);
				break;
			case 2:
				list.add(mMenu.getSignedInteger(1), TAIL);
				list.printList(HEAD);
				break;
			case 3:
				list.remove(HEAD);
				list.printList(HEAD);
				break;
			case 4:
				list.remove(TAIL);
				list.printList(HEAD);
				break;
			case 5:
				list.printList(TAIL);
				break;
			case 6:
				list.printList(HEAD);
				break;
		}
	} while (!exit);

	delete mainOptions;
	delete getIntegerOption;
	return 0;
}