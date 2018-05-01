/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Penguin class inherites properties from the Animal
** class. It has properties that indicate the age, cost, number of
** babies, basefoodcost, and payoff.
*********************************************************************/
#include "Penguin.hpp"

/**
 *	Penguin class default constructor
 */
Penguin::Penguin() : Animal(1000, 5) {
	setBaseFoodCost();
	setPayoff();
}

/**
 *	- A penguin cost $1,000
 *	- A penguin can only have 5 baby
 */
Penguin::Penguin(int age) : Animal(age, 1000, 5) {
	setBaseFoodCost();
	setPayoff();
}

/**
 *	Copy constructor overloaded
 */
Penguin & Penguin::operator=(const Penguin * rhs) {
	Animal::operator=(rhs);
}

/**
 *	Virtual function used to identify the class
 */
std::string Penguin::getClassName() const {
	return "Penguin";
}

/**
 *	Penguin's have a feeding cost of the baseFoodCost
 */
void Penguin::setBaseFoodCost() {}

/**
 *	A penguin's payoff per day is 10% of their cost per animal.
 *	Note: not counting bonus. 
 *	(e.g., Payoff = cost * 10% = 1000 * 0.1 = 1000)
 */
void Penguin::setPayoff() { payoff = cost * 0.1; }

/**
 *	Display the Penguin's properties
 */
void Penguin::showInfo() {
	std::cout << " {"
			  << " age: " << getAge() << ","
			  << " cost: " << getCost() << ","
			  << " numberOfBabies: " << getNumberOfBabies() << ","
			  << " payoff: " << getPayoff() << ","
			  << " baseFoodCost: " << getBaseFoodCost()
			  << " };\n";
}