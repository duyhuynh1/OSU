/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Locked item space class is dervied from the Space class.
** It has functions to return the item if the Player's inventory is empty.
*********************************************************************/
#ifndef LOCKED_ITEM_SPACE_HPP_
#define LOCKED_ITEM_SPACE_HPP_

#include "Space.hpp"

class LockedItemSpace : public Space {
    private:
        const std::string error = "Nothing inside the chest...\n";
        std::string item = " ";
        int numOfItems = 1;
        bool locked = true;
    public:
        LockedItemSpace(std::string);
        std::string getItem();
        bool isEmpty();
        bool isLocked();
        void trigger();
};
#endif  // LOCKED_ITEM_SPACE_HPP_