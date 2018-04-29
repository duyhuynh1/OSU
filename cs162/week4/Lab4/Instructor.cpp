/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Instructor class derives from the Person class.
** An instructor has a name, age, and also a rating. The "do_work"
** function is also overrided to indicate the amount of hours spent
** grading papers. The rating ranges from 0.0 - 5.0.
*********************************************************************/
#include "Instructor.hpp"

/**
 *  Instructor class default costructor
 *  @param name The Instructor's name
 *  @param age The Instructor's age
 *  @param rating The Instructor's rating. Range [ 0.0 - 5.0 ]
 */
Instructor::Instructor(std::string name, int age, float rating) : Person(name, age){
    this->name = name;
    this->age= age;
    this->rating = rating;
}

/**
 *  Instructor's do_work function indicates how many hours were
 *  spent grading papers.  message: “PERSON_NAME graded papers for X hours.” 
 *  Where PERSON_NAME is the person’s name, and X is the randomly 
 *  generated number.
 */
void Instructor::do_work() {
    std::cout << name << " graded papers for " 
              << (rand() % 12) + 1 << " hours." << std::endl;
}

/**
 *  Return the Instructor's rating
 */
float Instructor::getRating() { return rating; }