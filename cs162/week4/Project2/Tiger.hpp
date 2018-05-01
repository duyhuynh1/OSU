/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Tiger class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#ifndef	TIGER_HPP
#define TIGER_HPP
#include "Animal.hpp"

class Tiger : public Animal {
	public:
		Tiger();
		Tiger & operator=(const Tiger *);
		Tiger(int);
		std::string getClassName() const;
		void setBaseFoodCost();
		void setPayoff();
		void showInfo();
};
#endif	// TIGER_HPP