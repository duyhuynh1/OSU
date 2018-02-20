/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Create a Person object that stores the Person's name
** and age. Provides getter functions to acces the Person's name and
** age.
*********************************************************************/
#include "Person.hpp"

/** Default Person object constructor */
Person::Person(std::string mName, double mAge) {
	name = mName;
	age = mAge;
}

/**
 *	Returns the Person's name
 *	@return name The Person's name 
 */
std::string Person::getName() const {
	return name;
}

/**
 *	Returns the Person's age
 *	@return age The Person's age
 */
double Person::getAge() const {
	return age;
}