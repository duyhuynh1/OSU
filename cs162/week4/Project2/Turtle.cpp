/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Turtle class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#include "Turtle.hpp"

/**
 *	Turtle class default contructor
 */
Turtle::Turtle() : Animal(100, 10) {}

/**
 *	- A Turtle cost $100
 *	- A Turtle can only have 10 babies
 */
Turtle::Turtle(int age) : Animal(age, 100, 10) {
	std::cout << "Turtle::Turtle default constructor called" << std::endl;	// REMOVE
	setBaseFoodCost();
	setPayoff();
}

/**
 *	Virtual function used to identify the class
 */
std::string Turtle::getClassName() const {
	return "Turtle";
}

/**
 *	Turtle's have a feeding cost of half of the baseFoodCost
 */
void Turtle::setBaseFoodCost() { baseFoodCost *= 0.5; }

/**
 *	A Turtle's payoff per day is 5% of their cost per animal.
 *	Note: not counting bonus. 
 *	(e.g., Payoff = cost * 5% = 100 * 0.05 = 5)
 */
void Turtle::setPayoff() { payoff = cost * 0.05; }