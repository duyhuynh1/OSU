/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Locked door space class implementation. It requires
** a "door key" in order to open. When the door is locked it prevents
** the Player from exiting the labyrinth.
*********************************************************************/
#include "LockedDoorSpace.hpp"

/**
 *  Locked Door Space class default constructor
 */
LockedDoorSpace::LockedDoorSpace() : Space("LockedDoorSpace") {}

/**
 *  Returns true if the door is locked. Otherwise false.
 */
bool LockedDoorSpace::isLocked() { return (locked) ? true : false; }

/**
 *  Only gets triggered if the user has a "door key"
 */
void LockedDoorSpace::trigger() { locked = false; }