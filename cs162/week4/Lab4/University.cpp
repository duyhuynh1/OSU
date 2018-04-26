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
 *  Select a person to do work
 */
void University::selectPersonToDoWork(int index) { people[index - 1]->do_work(); }

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
    if (buildings.size() == 0) {
        std::cout << "Buildings database empty..." << std::endl;
    } else {
        std::cout << "=== BuildingDB ===" << "\n"
              << "+" << std::string(29, '-')
              << "+" << std::string(49, '-')
              << "+" << std::string(14, '-') << "+"
              << std::left  << std::setw(30) << "\n| Property Name"
              << std::left  << std::setw(50) <<  " | Address"
              << std::right << std::setw(15) <<  " | Usuable Sqft |\n"
              << "+" << std::string(29, '-')
              << "+" << std::string(49, '-')
              << "+" << std::string(14, '-') << "+\n";
        for (int i = 0; i < buildings.size(); i++) {
            std::cout << "| "
                      << std::left << std::setw(27) << buildings[i]->getName() << " | "
                      << std::left << std::setw(48) << buildings[i]->getAddress() << "|"
                      << std::right << std::setw(13) << buildings[i]->getSize() << " |\n";
        }
        std::cout << "+" << std::string(29, '-')
                  << "+" << std::string(49, '-')
                  << "+" << std::string(14, '-') << "+" << std::endl;
    }
    
}

/**
 *  Function that prints the information of all the people in its
 *  information system including: name, age, and (GPA or Rating)
 */
void University::getPeopleInfo() const {
    if (people.size() == 0) {
        std::cout << "People database empty..." << std::endl;
    } else {
        std::cout << "=== PeopleDB ===" << "\n"
                  << "+" << std::string(5, '-')
                  << "+" << std::string(12, '-')
                  << "+" << std::string(24, '-')
                  << "+" << std::string(5, '-')
                  << "+" << std::string(15, '-') << "+"
                  << std::left << std::setw(6)  << "\n| No."
                  << std::left << std::setw(13) <<  " | Type" 
                  << std::left << std::setw(25) <<  " | Name"
                  << std::left << std::setw(6)  <<  " | Age"
                  << std::left << std::setw(15) <<  " | Score         |\n"
                  << "+" << std::string(5, '-')
                  << "+" << std::string(12, '-')
                  << "+" << std::string(24, '-')
                  << "+" << std::string(5, '-')
                  << "+" << std::string(15, '-') << "+\n";
        for (int i = 0; i < people.size(); i++) {
            std::cout << "| " << std::right << std::setw(3) << (i + 1) << " |";
            if (typeid(* people[i]) == typeid(Instructor)) {
                std::cout << std::left << std::setw(12) << " Instructor";
            } else {
                std::cout << std::left << std::setw(12) << " Student";
            }
            std::cout << "|" << std::left  << std::setw(23) << people[i]->getName() << " |"
                      << std::right << std::setw(4) << people[i]->getAge() << " | ";
            // Run-time Type Indentification
            if (typeid(* people[i]) == typeid(Instructor)) {
                // Dynamic cast Person object to derived Instructor Object
                std::cout << std::right << std::setw(9) << "Rating: " << dynamic_cast<Instructor *>(people[i])->getRating() << " |\n";
            } else {
                // Dynamic cast Person object to derived Student Object
                std::cout << std::right << std::setw(9) << "GPA: " << dynamic_cast<Student *>(people[i])->getGPA() << " |\n";
            }
        }
        std::cout << "+" << std::string(5, '-')
                  << "+" << std::string(12, '-')
                  << "+" << std::string(24, '-')
                  << "+" << std::string(5, '-')
                  << "+" << std::string(15, '-') << "+\n";
    }
}

/**
 *  Return the University's number of buildings in the OSU database
 */
int University::getNumberOfBuildings() const { return buildings.size(); }

/**
 *  Return the Unversity's number of people registered on the OSU database
 */
int University::getNumberOfPeople() const { return people.size(); }