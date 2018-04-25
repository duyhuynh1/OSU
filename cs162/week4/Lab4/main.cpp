/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The driver program that allows the user to navigate
** through the OSU Information System.
*********************************************************************/
#include <iostream>
#include <fstream>          
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "University.hpp"
#include "Menu.hpp"
#include "Option.hpp"

void loadBuildingInfo(University &);
void loadPeopleInfo(University &);
void addNewBuildingInfo(University &);
void addNewPersonInfo(University &);

int main() {
    University mUniversity;
    loadBuildingInfo(mUniversity);
    loadPeopleInfo(mUniversity);
    mUniversity.getBuildingInfo();
    mUniversity.getPeopleInfo();

    // TODO: Write a queryDatabase() function to read in Building and Person objects

    // TEST REMOVE v
    // Person * person1 = new Student("Tony", 25, 3.99);
    // Person * person2 = new Instructor("Bob", 43, 4.89);
    // Person * person3 = new Student("John", 24, 3.75);

    // University mUniversity;
    // mUniversity.addPeople(person1);
    // mUniversity.addPeople(person2);
    // mUniversity.addPeople(person3);
    // // TEST REMOVE ^
    // std::string mainMenuPrompt = "1. Show all building information\n"
    //                              "2. Show all people information\n"
    //                              "3. Choose a person to do work\n"
    //                              "4. Exit program\n> ";
    // TODO: Need a menu that queries the name of all the people name
    // std::string doWorkPrompt = "Select a person to do work: ";

    // Option * option1 = new Option(mainMenuPrompt, 1, 4);
    // // Option * option2 = new Option(doWorkPrompt, );

    // Menu mMenu;
    // mMenu.addOption(option1);       // Index 0
    // // mMenu.addOption(option2);
    // std::cout << "===============================================\n"
    //           << "OSU INFORMATION SYSTEM\n"
    //           << "===============================================\n";
    // int selection = mMenu.getValue(0);

    // switch (selection) {
    //     case 1:
    //         std::cout << "Querying all building information..." << std::endl;
    //         break;
    //     case 2:
    //         std::cout << "Querying all people information..." << std::endl;
    //         mUniversity.getPeopleInfo();
    //         break;
    //     case 3:
    //         std::cout << "[D]: Choose a person to work menu" << std::endl;
    //         break;
    //     case 4:
    //         std::cout << ">>> Exit Program <<<" << std::endl;
    //         break;
    // }

    // delete option1;
    // delete option2;

    return 0;
}

/**
 *  Parses the BuildingInfo.txt file for Building information
 */
void loadBuildingInfo(University &mUniversity) {
    std::ifstream input;
    const std::string buildingInfoFilename = "./data/BuildingInfo.txt";
    bool success = false;
    do {
        input.open(buildingInfoFilename);
        if (input) {
            std::string name, address, size;
            while (std::getline(input, name, ',') &&
                   std::getline(input, address, ',') &&
                   std::getline(input, size)) {
                // Generate the Building Object
                mUniversity.addBuilding(new Building(name, address, std::stoi(size)));
            }
            success = true;
        } else {
            // TODO: Need to handle when build info is empty -> Return "Empty Database???"
            std::cout << "ERROR: failed to read\"" << buildingInfoFilename << "\"\n";
        }
    } while (!success);
    input.close();
}

/**
 *  Parses the PeopleInfo.txt file for Student and Instructor information
 */
void loadPeopleInfo(University &mUniversity) {
    std::ifstream input;
    const std::string peopleInfoFilename = "./data/PeopleInfo.txt";
    bool success = false;
    do {
        input.open(peopleInfoFilename);
        if (input) {
            std::string personType, name, age, value;
            while (std::getline(input, personType, ',') &&
                   std::getline(input, name, ',') &&
                   std::getline(input, age, ',') &&
                   std::getline(input, value)) {
                if (personType == "Student") {
                    mUniversity.addPeople(new Student(name, std::stoi(age), std::stof(value)));    
                } else {
                    mUniversity.addPeople(new Instructor(name, std::stoi(age), std::stof(value)));
                } 
            }
            success = true;
        } else {
            std::cout << "ERROR: failed to read\"" << peopleInfoFilename << "\"\n";
        }
    } while (!success);
    input.close();
}

/**
 *  Allows the user to add a new Building to the BuildingInfo.txt
 */


/**
 *  Allows the user to add a new Person to the PersonInfo.txt
 */
