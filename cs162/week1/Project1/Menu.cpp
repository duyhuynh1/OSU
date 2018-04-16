/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: Dynamic Menu that includes an integer validation 
** function to verify user inputs. 
*********************************************************************/
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"

/**
 *  The main menu which allows the user to start the simulation or quit
 */
void mainMenu() {
    std::cout << "==================================\n"
              << "LANGTON'S ANT SIMULATION\n"
              << "==================================\n";
    std::string mainMenuPrompt = "1. Start Langton's Ant simulation\n2. Quit\n"
                                 "----------------------------------\n> ";
    int selection = integerValidation(mainMenuPrompt, 1, 2);
    if (selection == 1) {
        startSimulation();
    } else {
        std::cout << "<<< Program Exit >>>" << std::endl;
    }
}
/**
 *  Prompts the user for all the necessary data to run simulation.
 *  All input will be validated to ensure simulation runs properly.
 */
void startSimulation() {
    std::string numberOfRowsPrompt = "Please enter the number of rows for the board: ";
    std::string numberOfColumnsPrompt = "Please enter the number of columns for the board: ";
    std::string numberOfStepsPrompt = "Please enter the number of steps during simulation: ";
    std::string randomLocationPrompt = "Place ant at random location?: \n1. Yes\n2. No\n> ";
    std::string startingRowPrompt = "Please enter the starting row of the ant: ";
    std::string startingColumnPrompt = "Please enter the starting column of the ant: ";

    int choice = integerValidation(randomLocationPrompt, 1, 2);
    int nRow = integerValidation(numberOfRowsPrompt, 1, INT_MAX);
    int nCol = integerValidation(numberOfColumnsPrompt, 1, INT_MAX);
    int steps = integerValidation(numberOfStepsPrompt, 1, INT_MAX);
    int xPos;
    int yPos;

    if (choice == 1) {
        srand(time(NULL));
        xPos = (rand() % nRow) + 1;
        yPos = (rand() % nCol) + 1;
    } else {
        std::cout << "[NOTE]: Rows and Columns start at 1\n";
        xPos = integerValidation(startingRowPrompt, 1, nRow);
        yPos = integerValidation(startingColumnPrompt, 1, nCol);
    }
    // Adjust positions since internally grid starts at [0,0]
    xPos -= 1;
    yPos -= 1;

    Board board(nRow, nCol);
    Board *boardPtr = &board;
    Ant ant(xPos, yPos, steps, boardPtr);
    while (ant.getSteps() >= 0) {
        ant.moveForward();
    }
    endMenu();
}

/**
 *  Re-prompt the user to play again or quit.
 */
void endMenu() {
    std::string endMenuPrompt = "----------------------------------\n"
                                "1. Play again\n2. Quit\n> ";
    int selection = integerValidation(endMenuPrompt, 1, 2);
    if (selection == 1) {
        startSimulation();       
    } else {
        std::cout << "<<< Program Exit >>>" << std::endl;
    }
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