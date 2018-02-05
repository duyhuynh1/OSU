/*********************************************************************
** Author: Tony Huynh
** Date: 2/07/2018
** Description: Taxicab class header file
*********************************************************************/
#ifndef TAXICAB_HPP
#define TAXICAB_HPP

// Taxicab class declaration
class Taxicab {
	private:
		int totalDistance;
		int xCoord;
		int yCoord;
	public:
		Taxicab(); // Default constructor, sets all variables = 0;
		Taxicab(int x, int y);
		int getXCoord() const;
		int getYCoord() const;
		int getDistanceTraveled() const;
		void moveX(int distance);
		void moveY(int distance);
};
#endif