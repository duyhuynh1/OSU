/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Dice class is the base class that provides all
** the necessary properties to create a Dice object. It stores the
** number of sides and the roll function simulats a dice roll.
*********************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

#include <cstdlib>     /* srand, rand */
#include <ctime>       /* time */

class Dice {
    protected:
        int numberOfSides;
    public:
        Dice(int side);
        virtual ~Dice();
        virtual int roll();
        int getNumberOfSides() const;
};
#endif  // DICE_HPP