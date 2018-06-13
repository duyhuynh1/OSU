/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Locked item space class implementation. It has functions to
** return the item if the Player's inventory is empty. It requires the
** Player to have a key in order to return the item.
*********************************************************************/
#include "LockedItemSpace.hpp"

LockedItemSpace::LockedItemSpace(std::string item) : Space("LockedItemSpace") {
    this->item = item;
}

std::string LockedItemSpace::getItem() {
    if (isLocked() == false && isEmpty() == false) {
        numOfItems--;
        return item;
    } else {
        return " ";
    }
}

bool LockedItemSpace::isEmpty() { return (numOfItems == 0) ? true : false; }

bool LockedItemSpace::isLocked() { return (locked) ? true : false; }

void LockedItemSpace::trigger() { locked = false; }