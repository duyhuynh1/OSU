/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Tiger class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#include "Tiger.hpp"

/**
 *	Tiger object default constructor with zero parameters
 */
Tiger::Tiger() : Animal(10000, 1) {
	setBaseFoodCost();
	setPayoff();
}

/**
 *	- A tiger cost $10,000
 *	- A tiger can only have 1 baby
 */
Tiger::Tiger(int age) : Animal(age, 10000, 1) {
	std::cout << "Tiger::Tiger default constructor called" << std::endl;	// REMOVE
	setBaseFoodCost();
	setPayoff();
}

/**
 *
 */
Tiger & Tiger::operator=(const Tiger * rhs) {
	std::cout << "Tiger::Tiger copy constructor called" << std::endl;
	Animal::operator=(rhs);
}

/**
 *	
 */
Tiger::~Tiger() {}

/**
 *	Virtual function used to identify the class
 */
std::string Tiger::getClassName() const {
	return "Tiger";
}

/**
 *	Tiger's have a feeding cost of 5 times the baseFoodCost
 */
void Tiger::setBaseFoodCost() { baseFoodCost *= 5; }

/**
 *	A tiger’s payoff per day is 20% of their cost per animal.
 *	Note: not counting bonus. 
 *	(e.g., Payoff = cost * 20% = 10000 * 0.2 = 2000)
 */
void Tiger::setPayoff() { payoff = cost * 0.2; }