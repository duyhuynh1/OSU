/*********************************************************************
** Author: Tony Huynh
** Date: 2/07/2018
** Description: Taxicab class implementation file
*********************************************************************/
#include <cstdlib>
#include "Taxicab.hpp"

/** Default constructor sets all variables to 0 */
Taxicab::Taxicab() {
	totalDistance = 0;
	xCoord = yCoord = 0;
}

/** Taxicab constructor with 2 args and sets totalDistance = 0 */
Taxicab::Taxicab(int x, int y) {
	totalDistance = 0;
	xCoord = x;
	yCoord = y;
}

/** Returns current x-coordinate value. */
int Taxicab::getXCoord() const {
	return xCoord;
}

/** Returns current y-coordinate value. */
int Taxicab::getYCoord() const {
	return yCoord;
}

/** Returns the total distance the Taxicab value has traveled. */
int Taxicab::getDistanceTraveled() const {
	return totalDistance;
}

/** Moves the Taxicab object in the x-coordinate. */
void Taxicab::moveX(int distance) {
	totalDistance += std::abs(distance);
	xCoord += distance;
}

/** Moves the Taxicab object in the y-coordinate. */
void Taxicab::moveY(int distance) {
	totalDistance += std::abs(distance);
	yCoord += distance;
}