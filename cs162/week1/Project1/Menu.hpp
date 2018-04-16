/*********************************************************************
** Program name: Langton's Ant
** Author: Tony Huynh
** Date: 04/15/2018
** Description: Menu function provides a template for future menu
** usage. It is dynamic enought to allow quick modifications to meet
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

#endif  // MENU_HPP