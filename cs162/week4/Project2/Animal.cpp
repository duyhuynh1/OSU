/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Animal class provides the required members to 
** inform the user about the Animal rhsect.
*********************************************************************/
#include "Animal.hpp"

/**
 *	
 */
Animal::Animal(int cost, int numberOfBabies) {
	this->cost = cost;
	this->numberOfBabies = numberOfBabies;
}

/**
 *	Animal class constructor with the following arguments
 *	@param age An integer representing the Animal's age
 *	@param cost an integer representing the Animal's cost
 *	@param numberOfBabies The amount of babies an animal can have
 */
Animal::Animal(int age, int cost, int numberOfBabies) {
	this->age = age;
	this->cost = cost;
	this->numberOfBabies = numberOfBabies;
}

/**
 *	Animal class copy constructor
 */
Animal & Animal::operator=(const Animal * rhs) {
	baseFoodCost = rhs->getBaseFoodCost();
	age = rhs->getAge();
	cost = rhs->getCost();
	numberOfBabies = rhs->getNumberOfBabies();
	payoff = rhs->getPayoff();
}

/**
 *	Animal class virtual destructor
 */
Animal::~Animal() {}

/**
 *	Virtual function used to identify the class
 */
std::string Animal::getClassName() const {
	return "Animal";
}

/**
 *	Return the Animal's basic food cost
 */
int Animal::getBaseFoodCost() const { return baseFoodCost; }

/**
 *	Set the Animal's baseFoodCost value
 */
void Animal::setBaseFoodCost() {};

/**
 *	Return the Animal's age
 */
int Animal::getAge() const { return age; }

/**
 *	Returns TRUE if Animal's age is greater or equal to 3. 
 * 	Otherwise FALSE if Animal's age is below 3.
 */
bool Animal::isAdult() {
	if (this->age >= 3) {

		return true;
	} else {

		return false;
	}
}

/**
 *	Used to increase the Animal's age each day
 */
void Animal::increaseAge() { this->age += 1; };

/**
 *	Return the Animal's cost
 */
int Animal::getCost() const { return cost; }

/**
 *	Return the number of babies the Animal can have
 */
int Animal::getNumberOfBabies() const { return numberOfBabies; }

/**
 *	Return the Animal's fixed payoff value
 */
int Animal::getPayoff() const { return payoff; }

/**
 *	Set the Animal's payoff value
 */
void Animal::setPayoff() {}

/**
 *	Indicate if the Animal can give birth
 */
bool Animal::canGiveBirth() {
	if (this->numberOfBabies > 0) {
		return true;
	} else {
		return false;
	}
}

/**
 *	Invoked once the Animal has given birth
 */
void Animal::hadChild() {
	this->numberOfBabies -= 1;
}