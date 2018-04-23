/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The driver program that sets up the Dice War Game. It
** prompts the user for inputs and provides user input validation.
*********************************************************************/
#include <iostream>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Menu.hpp"
#include "Option.hpp"

int main() {
    std::string mainMenuPrompt = "Welcome to Dice War Game!\n1. Play game \n2. Exit game\n> ";
    std::string numOfRoundsPrompt = "Number of rounds: ";
    std::string p1SelectDiePrompt = "Player1 select type of Die\n1. Normal Die\n2. Loaded Die\n> ";
    std::string p1DieNumOfSidesPrompt = "Player1 select number of sides for Die: ";
    std::string p2SelectDiePrompt = "Player2 select type of Die\n1. Normal Die\n2. Loaded Die\n> ";
    std::string p2DieNumOfSidesPrompt = "Player2 select number of sides for Die: ";

    Option * mainMenu = new Option(mainMenuPrompt, 1, 2);
    Option * numOfRoundsOption = new Option(numOfRoundsPrompt, 1, INT_MAX);
    Option * p1DieOption = new Option(p1SelectDiePrompt, 1, 2);
    Option * p1DieNumOfSidesOption = new Option(p1DieNumOfSidesPrompt, 2, INT_MAX);
    Option * p2DieOption = new Option(p2SelectDiePrompt, 1, 2);
    Option * p2DieNumOfSidesOption = new Option(p2DieNumOfSidesPrompt, 2, INT_MAX);

    Menu mMenu;
    mMenu.addOption(mainMenu);                  // 0
    mMenu.addOption(numOfRoundsOption);         // 1
    mMenu.addOption(p1DieNumOfSidesOption);     // 2
    mMenu.addOption(p1DieOption);               // 3
    mMenu.addOption(p2DieNumOfSidesOption);     // 4
    mMenu.addOption(p2DieOption);               // 5

    Die * die1 = NULL;
    Die * die2 = NULL;
    DieType p1DieType;
    DieType p2DieType;
    Player * p1 = NULL;
    Player * p2 = NULL;
    Game * mGame = NULL;
    int numOfRoundsSelection = 0;
    int p1DieSides = 0;
    int p2DieSides = 0;

    switch (mMenu.getValue(0)) {
        case 1:
            numOfRoundsSelection = mMenu.getValue(1);
            p1DieSides = mMenu.getValue(2);
            if (mMenu.getValue(3) == 1) {
                p1DieType = NORMAL_DIE;
                die1 = new Die(p1DieSides);
            } else {
                p1DieType = LOADED_DIE;
                die1 = new LoadedDie(p1DieSides);
            }
            p2DieSides = mMenu.getValue(4);
            if (mMenu.getValue(5) == 1) {
                p2DieType = NORMAL_DIE;
                die2 = new Die(p2DieSides);
            } else {
                p2DieType = LOADED_DIE;
                die2 = new LoadedDie(p2DieSides);
            }
            p1 = new Player("Player1", die1, p1DieType);
            p2 = new Player("Player2", die2, p2DieType);
            mGame = new Game(numOfRoundsSelection, p1, p2);
            mGame->start();
            break;
        case 2:
            std::cout << ">>> EXITING GAME <<<" << std::endl;
            break;
    }

    delete mainMenu;
    delete numOfRoundsOption;
    delete p1DieOption;
    delete p2DieOption;
    delete p1DieNumOfSidesOption;
    delete p2DieNumOfSidesOption;
    delete mGame;
    delete die1;
    delete die2;
    delete p1;
    delete p2;

    return 0;
}