/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: Defines constructors and functions used in the 
** Person class. Function includes:
** [1] getters for the Person's name and age.
*********************************************************************/
#ifndef	PERSON_HPP
#define PERSON_HPP

#include <string>

class Person {
	private:
		std::string name;
		double age;
	public:
		Person(std::string, double);
		std::string getName() const;
		double getAge() const;
};
#endif	// PERSON_HPP