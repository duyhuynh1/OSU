/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Zoo Tycoon game's driver program.
*********************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

int main() {
	std::cout << std::string(100, '=')
			  << "\nWelcome to Zoo Tycoon\n"
			  << std::string(100, '=');
	std::string mainMenuPrompt = "\n1. Start game\n2. Exit game\n> ";
	std::string zooOperationPrompt = "\n1. Purchase Animal"
									 "\n2. Open Zoo to Public"
									 "\n3. Exit game\n> ";
	std::string animalPurchasePrompt = "\n1. Purchase a Tiger ($10000)"
									   "\n2. Purchase a Penguin ($1000)"
									   "\n3. Purchase a Turtle ($100)"
									   "\n4. Cancel purchase\n> ";

	Option * option1 = new Option(mainMenuPrompt, 1, 2);
	Option * option2 = new Option(zooOperationPrompt, 1, 3);
	Option * option3 = new Option(animalPurchasePrompt, 1, 4);

	Menu mMenu;
	mMenu.addOption(option1);		// Index 0
	mMenu.addOption(option2);		// Index 1
	mMenu.addOption(option3);		// Index 2

	Zoo mZoo;
	int startAmount = 100000;
	switch (mMenu.getValue(0)) {
		case 1:
			mZoo.init(startAmount);
			while (mZoo.getGameState() == "PLAYING") {
				mZoo.showZooInfo();
				std::cout << std::string(100, '-') << std::endl;
				std::cout << "Player Action" << std::endl;
				std::cout << std::string(100, '-');
				switch (mMenu.getValue(1)) {
					case 1:
						std::cout << std::string(50, '-') << std::endl;
						std::cout << "[Account Balance]: $" << mZoo.getAccountBalance() << std::endl;
						std::cout << "What animal would you like to purchase?" << std::endl;
						std::cout << std::string(50, '-');
						switch (mMenu.getValue(2)) {
							case 1:
								if (mZoo.getAccountBalance() >= 10001) {
									mZoo.purchaseAnimal(TIGER);
									std::cout << "[ TRANSACTION SUCCESSFUL ]" << std::endl;
								} else {
									std::cout << "[ INSUFFICENT FUNDS ]" << std::endl;
								}
								break;
							case 2:
								if (mZoo.getAccountBalance() >= 1001) {
									mZoo.purchaseAnimal(PENGUIN);
									std::cout << "[ TRANSACTION SUCCESSFUL ]" << std::endl;
								} else {
									std::cout << "[ INSUFFICENT FUNDS ]" << std::endl;
								}
								break;
							case 3:
								if (mZoo.getAccountBalance() >= 101) {
									mZoo.purchaseAnimal(TURTLE);
									std::cout << "[ TRANSACTION SUCCESSFUL ]" << std::endl;
								} else {
									std::cout << "[ INSUFFICENT FUNDS ]" << std::endl;
								}
								break;
							case 4:
								std::cout << "[ TRANSACTION CANCELLED ]" << std::endl;
								break;
						}
						break;
					case 2:
						std::cout << "Opening park..." << std::endl;
						mZoo.running();
						std::cout << "[NEW ACCOUNT BALANCE]: $" << mZoo.getAccountBalance() << std::endl;
						break;
					case 3:
						mZoo.setGameState(END);
						std::cout << ">>> Exit Game <<<" << std::endl;
						break;
				}
			}
			break;
		case 2:
			std::cout << ">>> Exit Game <<<" << std::endl;
			break;
	}

	// Clean up
	delete option1;
	delete option2;
	delete option3;
	return 0;
}