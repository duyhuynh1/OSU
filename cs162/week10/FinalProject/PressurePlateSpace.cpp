/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Pressure plate class respresents a switch. It requires
** a heavy object in order to activate.
*********************************************************************/
#include <iostream>
#include "PressurePlateSpace.hpp"

PressurePlateSpace::PressurePlateSpace() : Space("PressurePlateSpace") {}

/**
 *
 */
bool PressurePlateSpace::isActivated() { return activated; }

/**
 *  
 */
void PressurePlateSpace::trigger() { activated = true; }