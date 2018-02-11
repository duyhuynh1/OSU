/*********************************************************************
** Author: Tony Huynh
** Date: 2/14/2018
** Description: Create a Player object that stores the Player's name,
** points, rebounds, and assists score. Provides getters/setters 
** functions to access and set the Player's name and stats. Also 
** provides the functionality to compare two player's points.
*********************************************************************/
#include "Player.hpp"

/** Default Player object constructor */
Player::Player() {
    name = "";
    setPoints(-1);
    setRebounds(-1);
    setAssists(-1);
}

/**
 *  Player object's constructor with 4 argurments. Initializes the Player's name,
 *  number of points, rebounds, and assists.
 *
 *  @param mName        The Player object's name
 *  @param numPoints    The Player object's number of points
 *  @param numRebounds  The Player object's number of rebounds
 *  @param numAssists   The Player object's number of assists
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
 *  Compares the points of two Player objects.  
 *
 *  @param aPlayer The other Player object that will be compared.
 *  @return        true if calling Player has more points, otherwise false
 */
bool Player::hasMorePointsThan(const Player &aPlayer) const {
   if (points > aPlayer.getPoints()) {
       return true; // The calling Player has more points
   } else {
       return false;
   }
}