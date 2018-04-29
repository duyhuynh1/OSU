/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: A Student object has the following properties: name,
** age, and GPA "Grade Point Average". The function "do_work" is 
** overriden to implement the student doing homeowork for X amount 
** of hours.
*********************************************************************/
#include "Student.hpp"

/**
 *  Student Object default constructor
 *  @param name The Student's name
 *  @param age The Student's age
 *  @param GPA The Student's GPA
 */
Student::Student(std::string name, int age, float GPA) : Person(name, age) {
    this->name = name;
    this->age = age;
    this->GPA = GPA;
}

/**
 *  Student Object do work function indicates how many hours the
 *  Student spent on doing homework.
 *  message: “PERSON_NAME did X hours of homework.” Where 
 *  PERSON_NAME is the person’s name, and X is the randomly generated number.
 */
void Student::do_work() {
    std::cout << name << " did " << (rand() % 12) + 1 
              << " hours of homework." << std::endl;
}

/**
 *  Return the Studen't GPA "Grade Point Average"
 */
float Student::getGPA() const { return GPA; }