/**
    @author Tony Huynh

    @date 2/14/2018
    @version v1.0.0
*/
#include "Player.hpp"

/** Default Player object constructor */
Player::Player() {
    name = "";
    setPoints(-1);
    setRebounds(-1);
    setAssists(-1);
}

/** 
    Player object constructor with # args 

    @param mName 
    @returns
*/
Player::Player(std::string mName, int numPoints, int numRebounds, int numAssists) {
    name = mName;
    setPoints(numPoints);
    setRebounds(numRebounds);
    setAssists(numAssists);
}

/** Sets the Player's name */
std::string Player::getName() const {
    return name;
}

/** Sets the Player's number of points*/
void Player::setPoints(int num) {
    points = num;
}

/** Returns the Player's number of points */
int Player::getPoints() const {
    return points;
}

/** Sets the Player's number of rebounds */
void Player::setRebounds(int num) {
    rebounds = num;
}

/** Returns the Player's number of rebounds */
int Player::getRebounds() const {
    return rebounds;
}

/** Sets the Player's number of assists */
void Player::setAssists(int num) {
    assists = num;
}

/** Returns the Player's number of assists */
int Player::getAssists() const {
    return assists;
}

/**
 *  Compares the total points of two Player objects.  
 *
 *  @param aPlayer Another Player object. The calling Player
 *  object's total number of points will be compared with 
 *  the passed in Player argument.
 *  @return TRUE if calling Player has more points, otherwise FALSE
 */
bool Player::hasMorePointsThan(const Player &aPlayer) const {
   int totalPointsP1 = points + rebounds + assists;
   int totalPointsP2 = aPlayer.getPoints() + 
                       aPlayer.getAssists() +
                       aPlayer.getRebounds();
   if (totalPointsP1 > totalPointsP2) {
       return true;
   } else {
       return false;
   }
}