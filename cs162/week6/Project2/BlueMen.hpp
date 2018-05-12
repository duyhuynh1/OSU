/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Blue Men class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Mob".
*********************************************************************/
// Mob: Blue Men are actually a swarm of small
// individuals. For every 4 points of damage, they
// lose one defense die. For example, if they have a
// strength of 8, they would have 2d6 for defense

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class BlueMen : public Character {
    public:
        BlueMen();
        void defend(int &);
};
#endif  // BLUE_MEN_HPP