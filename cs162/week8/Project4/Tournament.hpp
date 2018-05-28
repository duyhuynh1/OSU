/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The game class is used to control the flow of the game.
** Controls include the players in queue and combat info.
*********************************************************************/
#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iomanip>
#include "Menu.hpp"
#include "Option.hpp"
#include "Queue.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"

class Tournament {
    private:
        int rounds = 0;
        int numOfPlayersPerTeam = 0;    // NEED?
        Character *p1 = nullptr;
        Character *p2 = nullptr;
        Character *attacker = nullptr;
        Character *defender = nullptr;
        Queue *teamA = nullptr;
        Queue *teamB = nullptr;
        Queue *loserPile = nullptr;
        void swapRole(Character *, Character *);
    public:
        ~Tournament();
        void init(Queue *, Queue *, Queue *);
        void start();
        void getLineup(Menu);
        void setupNextFight();
        void getInfo();
        void getQueueInfo();
};
#endif  // TOURNAMENT_HPP