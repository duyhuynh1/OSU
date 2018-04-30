/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Tiger class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#ifndef	PENGUIN_HPP
#define PENGUIN_HPP
#include "Animal.hpp"

class Penguin : public Animal {
	public:
		Penguin();
		Penguin(int);
		std::string getClassName() const;
		void setBaseFoodCost();
		void setPayoff();
};
#endif	// PENGUIN_HPP