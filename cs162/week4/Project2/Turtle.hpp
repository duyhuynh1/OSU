/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Turtle class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#ifndef	TURTLE_HPP
#define TURTLE_HPP
#include "Animal.hpp"

class Turtle : public Animal {
	public:
		Turtle();
		Turtle(int);
		Turtle & operator=(const Turtle *);
		std::string getClassName() const;
		void setBaseFoodCost();
		void setPayoff();
		void showInfo();
};
#endif	// TURTLE_HPP