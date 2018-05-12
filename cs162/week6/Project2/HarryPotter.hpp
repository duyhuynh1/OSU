/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Harry Potter class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Hogwart".
*********************************************************************/
#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class HarryPotter : public Character {
    private:
        bool wasResurrected = false;
    public:
        HarryPotter();
        void defend(int &);
        bool getResurrected() const;
};
#endif  // HARRY_POTTER_HPP