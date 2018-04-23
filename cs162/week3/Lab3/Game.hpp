/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Game class keeps track of each Player's rolls and
** enforces the rules of the Dice game.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "Player.hpp"

class Game {
    private:
        int rounds;
        int playerScore[2];
        std::vector<Player *> contestants;
        void displayResults();
    public:
        Game(int rounds, Player *, Player *);
        void start();
};
#endif  // GAME_HPP