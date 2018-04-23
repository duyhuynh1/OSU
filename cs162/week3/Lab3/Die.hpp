/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Die class is the base class that provides all
** the necessary properties to create a Die object. It stores the
** number of sides and the roll function simulats a dice roll.
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

class Die {
    protected:
        int numberOfSides;
    public:
        Die(int side);
        virtual ~Die();
        virtual int roll();
        int getNumberOfSides() const;
};
#endif  // DIE_HPP