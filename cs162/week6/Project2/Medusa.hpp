/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Medusa class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Glare".
*********************************************************************/
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa : public Character {
    public:
        Medusa();
        void attack(Character *);
};
#endif  // MEDUSA_HPP