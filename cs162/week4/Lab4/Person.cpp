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
 *  
For “do_work()” in Person class, if the Person is an Instructor, 
then the function should output the following message: 
“PERSON_NAME graded papers for X hours.” Where PERSON_NAME is the 
person’s name, and X is the randomly generated number.
*/
void Person::do_work() {
    std::cout << name << " did " << (rand() % 12) + 1 << " hours of work." << std::endl;
}