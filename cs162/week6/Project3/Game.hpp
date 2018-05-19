/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The game class is used to control the flow of the game.
** Controls include the players in queue and combat info.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iomanip>
#include "Character.hpp"

class Game {
    private:
        int rounds = 0;
        Character *attacker = nullptr;
        Character *defender = nullptr;
        Character *p1 = nullptr;
        Character *p2 = nullptr;
        void swapRole(Character *, Character *);
    public:
        void init(Character *, Character *);
        void start();
        void getInfo();
};
#endif  // GAME_HPP