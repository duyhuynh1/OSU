/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The University Class stores the information about
** Buildings and people that work for or study at OSU.
*********************************************************************/
#include "University.hpp"

/**
 *  University class default constructor
 */
University::University() {  // REMOVE
    std::cout << "[D]: University constructor called" << std::endl; // REMOVE
}

University::~University() {
    std::cout << "[D]: University destructor called" << std::endl;  // REMOVE
    for (int i = 0; i < buildings.size(); i++) {
        delete buildings[i];
    }
    for (int i = 0; i < people.size(); i++) {
        delete people[i];
    }
}

/**
 *  Appends a Building object to the buildings vector
 */
void University::addBuilding(Building * mBuilding) { buildings.push_back(mBuilding); }

/**
 *  Appends a Person object to the people vector 
 */
void University::addPeople(Person * mPerson) { people.push_back(mPerson); }

/**
 *  Function that prints the information for all buildings in its
 *  information system including: name, address, and building's size
 */
void University::getBuildingInfo() const {
    std::cout << "+" << std::string(29, '-')
              << "+" << std::string(49, '-')
              << "+" << std::string(15, '-')
              << std::left << std::setw(30) << "\n| Property Name"
              << std::left << std::setw(50) << " | Address"
              << std::right << std::setw(15) << " | Usuable Sqft |\n"
              << "+" << std::string(29, '-')
              << "+" << std::string(49, '-')
              << "+" << std::string(15, '-') << std::endl;
    for (int i = 0; i < buildings.size(); i++) {
        std::cout << "| "
                  << std::left << std::setw(27) << buildings[i]->getName() << " |"
                  << std::left << std::setw(49) << buildings[i]->getAddress() << "|"
                  << std::right << std::setw(13) << buildings[i]->getSize() << " |\n";
    }
    std::cout << "+" << std::string(29, '-')
              << "+" << std::string(49, '-')
              << "+" << std::string(15, '-') << std::endl;
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