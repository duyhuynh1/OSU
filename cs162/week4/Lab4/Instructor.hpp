/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Instructor class dervices from the Person class. 
** An instructor has a name, age and also a rating. The "do_work"
** function is also overrided to indicate the amount of hours spent
** grading papers.
*********************************************************************/
#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include <iostream>
#include "Person.hpp"

class Instructor : public Person {
    private:
        std::string name;
        int age;
        float rating;   // Range { 0.0 - 5.0 }
    public:
        Instructor(std::string, int, float);
        void do_work() override;
        float getRating();
};
#endif  // INSTRUCTOR_HPP