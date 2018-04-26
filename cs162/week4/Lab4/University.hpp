/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The University Class stores the information about
** Buildings and people that work for or study at OSU. Building info
** include: 
*********************************************************************/
#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Building.hpp"
#include "Person.hpp"
#include "Instructor.hpp"
#include "Student.hpp"

class University {
    private:
        const std::string name = "Oregon State University";
        std::vector<Building *> buildings;
        std::vector<Person *> people;
    public:
        University();
        ~University();
        void selectPersonToDoWork(int);
        void addBuilding(Building *);
        void addPeople(Person *);
        void getBuildingInfo() const;
        void getPeopleInfo() const;
        int getNumberOfBuildings() const;
        int getNumberOfPeople() const;
};
#endif  // UNIVERSITY_HPP