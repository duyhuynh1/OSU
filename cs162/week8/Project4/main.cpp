/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/1618
** Description: Driver program that allows user to test different
** types of characters in combat.
*********************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

int main() {
    Barbarian *p1 = new Barbarian();
    Barbarian *p2 = new Barbarian();

    p1->attack(p2);
    p2->recoverStrengthPoints();
    // std::string mainMenuPrompt = "1) 1 vs 1 Battle\n2) Exit Game\n=> ";
    // std::string playerSelectionPrompt = "1) Vampire\n2) Barbarian\n3) Blue Men\n"
    //                                     "4) Medusa\n5) Harry Potter\n=> ";
    // std::string replayMenuPrompt = "1) Play Again\n2) Exit Game\n=> ";

    // Character *p1 = nullptr;
    // Character *p2 = nullptr;
    // Game mGame;

    // Option *option1 = new Option(mainMenuPrompt, 1, 2);
    // Option *option2 = new Option(playerSelectionPrompt, 1, 5);
    // Option *option3 = new Option(playerSelectionPrompt, 1, 5);
    // Option *option4 = new Option(replayMenuPrompt, 1, 2);
    // Menu mMenu;
    // mMenu.addOption(option1);   // Index 0
    // mMenu.addOption(option2);   // Index 1
    // mMenu.addOption(option3);   // Index 2
    // mMenu.addOption(option4);   // Index 3

    // int playerOneSeletion = 0;
    // int playerTwoSelection = 0;

    // bool done = false;
    // do {
    //     std::cout << std::string(50, '=') << std::endl;
    //     std::cout << "Fantasy Combat Game\n";
    //     std::cout << std::string(50, '=') << std::endl;
    //     switch (mMenu.getUnsignedInteger(0)) {
    //         case 1:
    //             std::cout << std::string(50, '-') << std::endl;
    //             std::cout << "Player 1 Character Selection\n";
    //             std::cout << std::string(50, '-') << std::endl;
    //             playerOneSeletion = mMenu.getUnsignedInteger(1);
    //             switch (playerOneSeletion) {
    //                 case 1:
    //                     p1 = new Vampire();
    //                     break;
    //                 case 2:
    //                     p1 = new Barbarian();
    //                     break;
    //                 case 3:
    //                     p1 = new BlueMen();
    //                     break;
    //                 case 4:
    //                     p1 = new Medusa();
    //                     break;
    //                 case 5:
    //                     p1 = new HarryPotter();
    //                     break;
    //             }
    //             std::cout << std::string(50, '-') << std::endl;
    //             std::cout << "Player 2 Character Selection\n";
    //             std::cout << std::string(50, '-') << std::endl;
    //             playerTwoSelection = mMenu.getUnsignedInteger(2);
    //             switch (playerTwoSelection) {
    //                 case 1:
    //                     p2 = new Vampire();
    //                     break;
    //                 case 2:
    //                     p2 = new Barbarian();
    //                     break;
    //                 case 3:
    //                     p2 = new BlueMen();
    //                     break;
    //                 case 4:
    //                     p2 = new Medusa();
    //                     break;
    //                 case 5:
    //                     p2 = new HarryPotter();
    //                     break;
    //             }
    //             mGame.init(p1, p2);
    //             mGame.start();
    //             if (mMenu.getUnsignedInteger(3) == 2) {
    //                 done = true;
    //                 std::cout << ">>> EXIT GAME <<<" << std::endl;
    //             }
    //             delete p1;
    //             delete p2;
    //             break;
    //         case 2:
    //             done = true;
    //             std::cout << ">>> EXIT GAME <<<" << std::endl;
    //             break;
    //     }
    // } while(!done);

    // delete option1;
    // delete option2;
    // delete option3;
    // delete option4;
	return 0;
}