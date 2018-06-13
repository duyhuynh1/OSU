/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Item space class implementation. It has functions to
** return the item if the Player's inventory is empty.
*********************************************************************/
#include <iostream>
#include "ItemSpace.hpp"

/**
 *  Item Space default constructor
 */
ItemSpace::ItemSpace(std::string item) : Space("ItemSpace") {
    this->item = item;
}

/**
 *  
 */
std::string ItemSpace::getItem() { 
    if (numOfItems >= 1) {
        numOfItems--;
        return item;
    } else {
        std::cout << error;
        return " ";
    }
}

/**
 *  Check if ItemSpace no longer has items
 */
bool ItemSpace::isEmpty() { return (numOfItems == 0) ? true : false; }