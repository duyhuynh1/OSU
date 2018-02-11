/*********************************************************************
** Author: Tony Huynh
** Date: 2/14/2018
** Description: Defines the constructors and functions used in the
** Player class. Functions includes:
** [1] getters and setters for the Player's points.
** [2] comparison of two Player's points. 
*********************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

class Player {
    private:
        std::string name;
        int points;
        int rebounds;
        int assists;
    public:
        Player();
        Player(std::string, int, int, int);
        std::string getName() const;
        void setPoints(int);
        int getPoints() const;
        void setRebounds(int);
        int getRebounds() const;
        void setAssists(int);
        int getAssists() const;
        bool hasMorePointsThan(const Player &) const;
};
#endif // PLAYER_HPP