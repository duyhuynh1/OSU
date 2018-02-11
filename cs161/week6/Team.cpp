/*********************************************************************
** Author: Tony Huynh
** Date: 2/14/2018
** Description: Create a Team object that consists of 5 Player objects.
** Getters and setter functions are provided to access Player's 
** information. Also provided is the functionality to calculate the 
** Team's total player points.
*********************************************************************/
#include "Team.hpp"

/** Default Team object constructor */
Team::Team(Player mPointGuard, Player mShootingGuard,
           Player mSmallForward, Player mPowerForward,
           Player mCenter) {
    setPointGuard(mPointGuard);
    setShootingGuard(mShootingGuard);
    setSmallForward(mSmallForward);
    setPowerForward(mPowerForward);
    setCenter(mCenter);
}

/** 
 *  Add's a point guard Player to the Team.
 *
 *  @param Player The Player object.
 */
void Team::setPointGuard(const Player &mPointGuard) {
    pointGuard = mPointGuard;
}

/** Returns the Team's point guard Player */
Player Team::getPointGuard() const {
    return pointGuard;
}

/** 
 *  Add's a shooting guard Player to the Team.
 *
 *  @param Player The Player object. 
 */
void Team::setShootingGuard(const Player &mShootingGuard) {
    shootingGuard = mShootingGuard;
}

/** Returns the Team's shooting guard Player */
Player Team::getShootingGuard() const {
    return shootingGuard;
}

/**
 *  Add's a small forward Player to the Team.
 *
 *  @param Player The Player object.
 */
void Team::setSmallForward(const Player &mSmallForward) {
    smallForward = mSmallForward;
}

/** Returns the Team's small foward Player */
Player Team::getSmallForward() const {
    return smallForward;
}

/**
 *  Add's a power forward Player to the Team.
 *
 *  @param Player The Player object.
 */
void Team::setPowerForward(const Player &mPowerForward) {
    powerForward = mPowerForward;
}

/** Returns the Team's power forward Player */
Player Team::getPowerForward() const {
    return powerForward;
}

/**
 *  Add's a center Player to the Team.
 *
 *  @param Player The Player object.
 */
void Team::setCenter(const Player &mCenter) {
    center = mCenter;
}

/** Returns the Team's center Player */
Player Team::getCenter() const {
    return center;
}

/** Returns the Team's total points */
int Team::totalPoints() const {
    return getPlayerPoints(pointGuard) + getPlayerPoints(shootingGuard) +
           getPlayerPoints(smallForward) + getPlayerPoints(powerForward) +
           getPlayerPoints(center);
}

/**
 *  Access's the Player's points value.
 *  
 *  @param mPlayer The Player object
 *  @return        The Player's points value.
 */
int Team::getPlayerPoints(Player mPlayer) const {
    return mPlayer.getPoints();
}