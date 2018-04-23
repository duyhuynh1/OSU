/*********************************************************************
** Program name: War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: Menu function provides a template for future menu
** usage. It is dynamic enough to allow quick modifications to meet
** different needs.
*********************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>	// INT_MAX

void mainMenu();
void startSimulation();
void endMenu();
int integerValidation(std::string prompt, int min, int max);
std::string stringValidation(std::string prompt);

#endif  // MENU_HPP