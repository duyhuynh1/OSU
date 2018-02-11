/*********************************************************************
** Author: Tony Huynh
** Date: 2/14/2018
** Description: Defines the constructors and functions used in the
** Team class. Functions includes:
** [1] Getters and setters for the Player objects.
** [2] Calculates the Team's total points.
*********************************************************************/
#ifndef TEAM_HPP
#define TEAM_HPP

#include "Player.hpp"

class Team {
    private:
        Player pointGuard;
        Player shootingGuard;
        Player smallForward;
        Player powerForward;
        Player center;
        int getPlayerPoints(Player) const;
    public:
        Team(Player, Player, Player, Player, Player);
        void setPointGuard(const Player &);
        Player getPointGuard() const;
        void setShootingGuard(const Player &);
        Player getShootingGuard() const;
        void setSmallForward(const Player &);
        Player getSmallForward() const;
        void setPowerForward(const Player &);
        Player getPowerForward() const;
        void setCenter(const Player &);
        Player getCenter() const;
        int totalPoints() const;
};
#endif  // TEAM_HPP