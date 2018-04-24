/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The University Class stores the information about
** Buildings and people that work for or study at OSU.
*********************************************************************/
#include "University.hpp"
// TODO: https://stackoverflow.com/questions/9560861/downcasting-from-base-pointer-to-templated-derived-types


/**
 *  University class default constructor
 */
University::University() {
    std::cout << "[D]: University constructor called" << std::endl; // REMOVE
}

/**
 *  Appends a Building object to the buildings vector
 */
void University::addBuilding(Building * mBuilding) {
    buildings.push_back(mBuilding);
}

/**
 *  Appends a Person object to the people vector 
 */
void University::addPeople(Person * mPerson) {
    people.push_back(mPerson);
}

/**
 *  Function that prints the information for all buildings in its
 *  information system including: name, address, and building's size
 */
// TODO: Add dynamic width adjustments
void University::getBuildingInfo() const {
    for (int i = 0; i < buildings.size(); i++) {
        std::cout << "[ Property Name: " << buildings[i]->getName() << " | "
                  << "Address: " << buildings[i]->getAddress() << " | "
                  << "Usuable Sqft: " << buildings[i]->getSize() << " ]" << std::endl;
    }
}

/**
 *  Function that prints the information of all the people in its
 *  information system including: name, age, and (GPA or Rating)
 */
// TODO: Add dynamic width adjustments
void University::getPeopleInfo() const {
    for (int i = 0; i < people.size(); i++) {
        std::cout << "[ Name: " << people[i]->getName() << " | "
                  << "Age: " << people[i]->getAge() << " | ";
        // Run-time Type Indentification
        if (typeid(* people[i]) == typeid(Instructor)) {
            // Dynamic cast Person object to derived Instructor Object
            std::cout << "Rating: " << dynamic_cast<Instructor *>(people[i])->getRating() << " ]\n";
        } else {
            // Dynamic cast Person object to derived Student Object
            std::cout << "GPA: " << dynamic_cast<Student *>(people[i])->getGPA() << " ]\n";
        }
    }
}