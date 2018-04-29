/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Person class is polymorphic. A Person object has
** a name and an age. As well as a function that represents the 
** person's activity.
*********************************************************************/
#include "Person.hpp"

/**
 *  Person class default constructor
 *  @param name The person's name
 *  @param age The person's age
 */
Person::Person(std::string name, int age) {
    this->name = name;
    this->age = age;
    srand(time(0));
}

/**
 *  Person class virtual destructor
 */
Person::~Person() {}

std::string Person::getName() const { return name; }

/**
 *  Returns the Peron's age
 */
int Person::getAge() const { return age; }

/**
 *	Depending on the type of person the Person does different tasks for
 *	X amount of hours.
 */
void Person::do_work() {
    std::cout << name << " did " << (rand() % 12) + 1 << " hours of work." << std::endl;
}