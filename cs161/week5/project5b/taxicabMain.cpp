/*********************************************************************
** Author: Tony Huynh
** Date: 2/07/2018
** Description: 
*********************************************************************/
#include <iostream>
#include "Taxicab.hpp"

// Function prototype
void toString(const Taxicab &t);

/* Unit Testing */
int main() {
	// TEST_1:
	std::cout << "[TEST_1]: Default Contructor" << std::endl;
	Taxicab mCab1;
	std::cout << "Result: ";
	toString(mCab1);
	std::cout << "Expect: Taxicab{ xCoord: 0; yCoord: 0; totalDistance: 0 }" << std::endl;
	std::cout << "---------------------------------------------------------" << std::endl;
	Taxicab mCab2(5, -8);
	mCab1.moveX(3);
	mCab1.moveY(-4);
	mCab1.moveX(-1);
	mCab2.moveY(7);
	toString(mCab1);
	toString(mCab2);

	return 0;
}

void toString(const Taxicab &t) {
	std::cout << "Taxicab{ ";
	std::cout << "xCoord: " << t.getXCoord() << "; ";
	std::cout << "yCoord: " << t.getYCoord() << "; ";
	std::cout << "totalDistance: " << t.getDistanceTraveled();
	std::cout << " }" << std::endl;
}