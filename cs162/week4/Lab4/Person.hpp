/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Person class is polymorphic. A Person object can
** be an Instructor or a Student.
*********************************************************************/
#ifndef PERSON_HPP
#define PERSON_HPP

#include <iostream>
#include <cstdlib>      // srand, rand
#include <ctime>        // time

class Person {
    private:
        std::string name;
        int age;
    public:
        Person(std::string, int);
        virtual ~Person();
        std::string getName() const;
        int getAge() const;
        virtual void do_work();
};
#endif  // PERSON_HPP