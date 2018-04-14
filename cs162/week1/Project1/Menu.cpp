/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
*********************************************************************/
#include <ctime>    // REMOVE???
#include <cstdlib>  // REMOVE???
#include "Menu.hpp"
#include "Board.hpp"
#include "Ant.hpp"

void startSimulation() {
    // const std::string mainMenuPrompt = "1.  Start Langton's Ant simulation\n2.  Quit\n----------------------------------\n> ";
    // const std::string numberOfRowsPrompt = "Please enter the number of rows for the board: ";
    // const std::string numberOfColumnsPrompt = "Please enter the number of columns for the board: ";

    int nRow = getBoardRows();
    int nCol = getBoardColumns();
    int steps = getNumberOfSteps();
    int xPos;
    int yPos;

    if (startAtRandomLocation()) {
        srand(time(NULL));
        xPos = rand() % nRow;
        yPos = rand() % nCol;
    } else {
        std::cout << "[NOTE]: Rows and Colums start at 0\n";
        xPos = getAntStartingRow(nRow);
        yPos = getAntStartingColumn(nCol);
    }

    Board board(nRow, nCol);
    Board *boardPtr = &board;
    Ant ant(xPos, yPos, steps, boardPtr);
    while (ant.getSteps() > 0) {
        ant.moveForward();
    }
    endMenu();
}

/**
 *  The main menu
 */
void mainMenu() {
    std::cout << "==================================\n"
              << "LANGTON'S ANT SIMULATION\n"
              << "==================================\n";
    std::string prompt = "1.  Start Langton's Ant simulation\n2.  Quit\n----------------------------------\n> ";
    int min = 1;
    int max = 2;
    int selection = integerValidation(prompt, min, max);

    if (selection == 1) {
        startSimulation();
    } else {
        std::cout << "<<< Program Exit >>>" << std::endl;
    }
}

/**
 *  Return
 */
int getBoardRows() {
    std::string prompt = "Please enter the number of rows for the board: ";
    int min = 1;
    int max = INT_MAX;
    return integerValidation(prompt, min, max);
}

/**
 *  Return
 */
int getBoardColumns() {
    std::string prompt = "Please enter the number of columns for the board: ";
    int min = 1;
    int max = INT_MAX;
    return integerValidation(prompt, min, max);
}

/**
 *  Return ???
 */
// TODO: Should we allow steps of 0?
int getNumberOfSteps() {
    std::string prompt = "Please enter the number of steps during simulation: ";
    int min = 0;
    int max = INT_MAX;
    return integerValidation(prompt, min, max);
}

/**
 *  Return TRUE if user selects to start the Ant at a random location.
 *  Otherwise FALSE if user chooses to select the Ant's starting location.
 */
bool startAtRandomLocation() {
    std::string prompt = "Place ant at random location?: \n1. Yes\n2. No\n> ";
    int min = 1;
    int max = 2;
    return integerValidation(prompt, min, max);
}

/**
 *  Return ???
 *  @param rowLimit
 */
// TODO: Change the xPostion of the Ant
int getAntStartingRow(int rowLimit) {
    std::string prompt = "Please enter the starting row of the ant: ";
    int min = 0;    // TODO: lets give the user the option to input 1
    int max = rowLimit;
    return integerValidation(prompt, min, max);
}

/**
 *  Return ????
 *  @param columLimit An integer representing the Board's total columns
 */
 // TODO: Change the yPositioning of the Ant
int getAntStartingColumn(int columnLimit) {
    std::string prompt = "Please enter the starting column of the ant: ";
    int min = 0;
    int max = columnLimit;
    return integerValidation(prompt, min, max);
}

void endMenu() {
    std::string prompt = "----------------------------------\n1.  Play again\n2.  Quit\n> ";
    int min = 1;
    int max = 2;
    int selection = integerValidation(prompt, min, max);

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
 *  @return result 
 */
int integerValidation(std::string prompt, int min, int max) {
    std::string number;
    int result;
    bool valid = false;
    do {
        try {
            std::cout << prompt;
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
            // Invalid argument exeception caught (e.g., " ")
        } catch (std::out_of_range) {
            // Out of range exception caught
        }
        if (result >= min && result <= max) {
            valid = true;
            return result;
        }
    } while (!valid);
}