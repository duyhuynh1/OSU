/*********************************************************************
** Program name: War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: Dynamic Menu that includes an integer validation 
** function to verify user inputs. 
*********************************************************************/
#include "Menu.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

enum DieType { NORMAL = 1, LOADED = 2 };

/**
 *  The main menu which allows the user to start the game or quit
 */
void mainMenu() {
    std::string p1Name = "";
    std::string p2Name = "";
    int rounds = 0;
    int p1DieType = 0;
    int p2DieType = 0;
    Die * ptrP1Die = NULL;
    Die * ptrP2Die = NULL;
    Player * ptrPlayerP1 = NULL;
    Player * ptrPlayerP2 = NULL;
    Game * ptrGame = NULL;
    int numberOfSides = 0;

    std::string mainMenuPrompt = "\n1. Play game \n2. Exit game\n> ";
    std::string p1NamePrompt = "Enter Player1 name: ";
    std::string p2NamePrompt = "Enter Player2 name: ";
    std::string numOfRoundsPrompt = "Number of rounds: ";
    std::string p1SelectDiePrompt = "Player1 select type of Die\n1. Normal Die\n2. Loaded Die\n> ";
    std::string p2SelectDiePrompt = "Player2 select type of Die\n1. Normal Die\n2. Loaded Die\n> ";
    std::string numberOfSidesForDiePrompt = "Number of sides for die: ";

    int selection = integerValidation(mainMenuPrompt, 1, 2);                                // TEST CASE
    switch (selection) {
        case 1:
            std::cout << "Loading..." << std::endl;
            p1Name = stringValidation(p1NamePrompt);                                        // TEST CASE
            // p2Name = stringValidation(p2NamePrompt);                                     // TEST CASE
            rounds = integerValidation(numOfRoundsPrompt, 1, INT_MAX);                      // TEST CASE limitations?
            p1DieType = integerValidation(p1SelectDiePrompt, 1, 2);                         // TEST CASE use ENUM??
            // p2DieType = integerValidation(p2SelectDiePrompt, 1, 2);                      // TEST CASE use ENUM??
            numberOfSides = integerValidation(numberOfSidesForDiePrompt, 2, INT_MAX);       // TEST CASE limitations?
            // Die creation COULD BE REPLACED WITH FOR LOOP
            switch (p1DieType) {
                case NORMAL:
                    std::cout << "selected normal" << std::endl;
                    ptrP1Die = new Die(numberOfSides);
                    break;
                case LOADED:
                    std::cout << "selected loaded" << std::endl;
                    ptrP1Die = new LoadedDie(numberOfSides);
                    break;
            }

            ptrPlayerP1 = new Player(p1Name, ptrP1Die);

            ptrGame = new Game(rounds);
            ptrGame->addPlayer(ptrPlayerP1);
            // Player p1 = new Player();
            break;
        case 2:
            std::cout << ">>> Game Over <<<" << std::endl;
            break;
    }
}

/**
 *  Re-prompt the user to play again or quit.
 */
void endMenu() {
}

/**
 *  Validation algorithm will verify the user's input is an integer and check
 *  if the number is within the range specified by the min and max values
 *  @param prompt A message that display on the console to prompt user for input
 *  @param min An integer depicting the minimum integer allowed
 *  @param max An integer depicting the maximum integer allowed
 *  @return result if all conditions are met
 */
int integerValidation(std::string prompt, int min, int max) {
    std::string number;
    int result;
    bool valid = false;
    do {
        try {
            std::cout << prompt;
            // Analyze number to see if it only contains digits
            while (std::getline(std::cin, number) && number.end() != 
                   std::find_if_not(number.begin(), number.end(), &isdigit)) {
                std::cout << prompt;
            }
            // Handle empty inputs
            if (number.size() == 0) {
                result = -1;
            } else {
                result = stoi(number);
            }
        } catch (std::invalid_argument) {
            result = -1;    // Invalid argument exeception caught (e.g., " ")
        } catch (std::out_of_range) {
            result = -1;    // Out of range exception caught
        }
        if (result >= min && result <= max) {
            valid = true;
            return result;
        }
    } while (!valid);
}

/**
 *  Ensure Player's name is not empty
 */
std::string stringValidation(std::string prompt) {
    std::string result;
    bool valid = false;
    do {
        std::cout << prompt;
        std::getline(std::cin, result);
        if (result.size() != 0) {
            valid = true;
        }
    } while (!valid);
    return result;
}