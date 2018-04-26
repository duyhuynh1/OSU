/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Student class derives from the Person class.
** A Student has a name, age, and also a GPA. The "do_work" function 
** is also overrided to indicate the hours of homework done by the
** Student.
*********************************************************************/
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include "Person.hpp"

class Student : public Person {
    private:
        std::string name;
        int age;
        float GPA;      // Range { 0.0 - 4.0 }
    public:
        Student(std::string, int, float);
        void do_work() override;
        float getGPA() const;
};
#endif  // STUDENT_HPP