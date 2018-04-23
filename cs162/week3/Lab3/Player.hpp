/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Player class replicates a Player who has a Dice
** object.
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include "Die.hpp"

enum DieType { NORMAL_DIE, LOADED_DIE };

class Player {
    private:
    	DieType type;
    	int points = 0;
        std::string name = "";
        Die * ptrDie = NULL;
    public:
        Player(std::string name, Die * ptrDie, DieType type);
        std::string getName() const;
        int rollDie();
        void addPoints();
        int getPoints() const;
        std::string getDieType() const;
        int getDieNumberOfSides() const;
};
#endif  // PLAYER_HPP