/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Vampire class is a derived Character class. It 
** has attributes such as attack, defense, armor, strength, and has 
** the special ability "Charm" (Vampires can charm an opponent into 
** not attacking. For a given attack there is a 50% chance that their
** opponent does not actually attack them).
*********************************************************************/
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire : public Character {
		bool abilityActivated = false;
    public:
        Vampire();
        void defend(int &);
};
#endif  // VAMPIRE_HPP