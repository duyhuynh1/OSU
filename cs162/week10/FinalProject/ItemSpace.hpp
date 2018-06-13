/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Item space class is a derived Space class. It's main
** purpose is to store an item.
*********************************************************************/
#ifndef ITEM_SPACE_HPP_
#define ITEM_SPACE_HPP_

#include "Space.hpp"

class ItemSpace : public Space {
    private:
        // std::string synop
        const std::string error = "Nothing inside the chest...\n";
        std::string item = " ";
        int numOfItems = 1;
    public:
        ItemSpace(std::string);
        std::string getItem();
        bool isEmpty();
};
#endif  // ITEM_SPACE_HPP_