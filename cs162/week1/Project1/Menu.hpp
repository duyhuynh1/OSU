/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ADD COMMENTS HERE
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <climits>

void mainMenu();
void menuPrompt();
void createBoard();
int getBoardRows();
int getBoardColumns();
int getNumberOfSteps();
int getAntStartingRow(int rowLimit);
int getAntStartingColumn(int columnLimit);
bool startAtRandomLocation();
void startSimulation();
void endMenu();
int integerValidation(std::string prompt, int min, int max);

#endif  // MENU_HPP