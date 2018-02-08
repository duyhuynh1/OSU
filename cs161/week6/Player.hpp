/**
 *  @author Tony Huynh
 *
 *  @date 2/14/2018
 *  @version v1.0.0
 */
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
        Player(std::string n, int numPoints, int numRebounds, int numAssists);
        std::string getName() const;
        void setPoints(int num);
        int getPoints() const;
        void setRebounds(int num);
        int getRebounds() const;
        void setAssists(int num);
        int getAssists() const;
        bool hasMorePointsThan(const Player &aPlayer) const;
};
#endif // PLAYER_HPP