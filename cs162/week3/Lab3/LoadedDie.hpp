/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Loaded Die class is a derived class of the Die 
** Class. It's roll function is different from the Die class because
** it has a higher chance of returning a larger number
*********************************************************************/
#ifndef LOADED_DIE_HPP
#define LOADED_DIE_HPP

#include "Die.hpp"

class LoadedDie : public Die {
    private:
        int numberOfSides;
    public:
        LoadedDie(int);
        int roll();
};
#endif  /* LOADED_DIE_HPP */