/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Player class. It has functions that 
** allow the user to move, inspect, and interact with the current
** Space.
*********************************************************************/
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Space.hpp"
#include "Menu.hpp"
#include "Option.hpp"

class Player {
    private:
        Menu menu;
        bool exit = false;
        std::string inventory[1] = {" "};
        Space* current = nullptr;
        void showSpace(Space*);
    public:
        Player(Space&);
        void move();
        void inspectSpace();
        void store(std::string);
        void showInventory();
        void showPosition();
        bool foundExit();
};
#endif  // PLAYER_HPP_