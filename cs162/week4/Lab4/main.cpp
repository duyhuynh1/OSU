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

void loadBuildingInfo(University &, const std::string &);
void loadPeopleInfo(University &, const std::string &);
void addNewBuildingInfo(University &, const std::string &);
void addNewPersonInfo(University &, const std::string &);

int main() {
    const std::string buildingInfoFilename = "./data/BuildingInfo.txt";
    const std::string peopleInfoFilename = "./data/PeopleInfo.txt";

    University mUniversity;
    loadBuildingInfo(mUniversity, buildingInfoFilename);
    loadPeopleInfo(mUniversity, peopleInfoFilename);
    mUniversity.getBuildingInfo();
    mUniversity.getPeopleInfo();

    std::string mainMenuPrompt = "1. Show all building information\n"
                                 "2. Show all people information\n"
                                 "3. Choose a person to do work\n"
                                 "4. Add new building\n"
                                 "5. Add new person\n"
                                 "6. Exit program\n> ";
    std::string doWorkPrompt = "Select a person to do work: ";

    Option * option1 = new Option(mainMenuPrompt, 1, 6);
    Option * option2 = new Option(doWorkPrompt, 1, );

    Menu mMenu;
    mMenu.addOption(option1);       // Index 0

    // mMenu.addOption(option2);
    std::cout << "===============================================\n"
              << "OSU INFORMATION SYSTEM\n"
              << "===============================================\n";
    int selection = mMenu.getValue(0);

    switch (selection) {
        case 1:
            std::cout << "Querying all building information..." << std::endl;   // REMOVE
            mUniversity.getBuildingInfo();
            break;
        case 2:
            std::cout << "Querying all people information..." << std::endl; // REMOVE
            mUniversity.getPeopleInfo();
            break;
        case 3:
            std::cout << "[D]: Choose a person to work menu" << std::endl;  // REMOVE
            break;
        case 4:
            std::cout << "[D]: Add a new building" << std::endl;    // REMOVE
            addNewBuildingInfo();
            break;
        case 5:
            std::cout << "[D]: Add a new person" << std::endl;  // REMOVE
            addNewPersonInfo();
            break;
        case 6:
            std::cout << ">>> Exit Program <<<" << std::endl;
            break;
    }

    delete option1;
    delete option2;

    return 0;
}

/**
 *  Parses the BuildingInfo.txt file for Building information
 */
void loadBuildingInfo(University &mUniversity, const std::string &filename) {
    std::ifstream input;
    bool success = false;
    do {
        input.open(filename);
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
            std::cout << "ERROR: failed to read\"" << filename << "\"\n";
        }
    } while (!success);
    input.close();
}

/**
 *  Parses the PeopleInfo.txt file for Student and Instructor information
 */
void loadPeopleInfo(University &mUniversity, const std::string &filename) {
    std::ifstream input;
    bool success = false;
    do {
        input.open(filename);
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
            std::cout << "ERROR: failed to read\"" << filename << "\"\n";
        }
    } while (!success);
    input.close();
}

/**
 *  Allows the user to add a new Building to the BuildingInfo.txt
 *  Request user for the Building's name, 
 */
// TODO: Update buildings.push_back();
void addNewBuildingInfo(University &mUniversity, const std::string &filename) {
    std::ofstream output;
    bool success = false;
    do {
        output.open();
        std::cout << "=== Adding new building ===";
        std::cout << "Please enter name: ";
        std::cout << "Please enter address: ";
        std::cout << "Please enter ";
        success = true;
    } while (!success);
}

/**
 *  Allows the user to add a new Person to the PersonInfo.txt
 */
// TODO: Update people.push_back();
void addNewPersonInfo(University &mUniversity, const std::string &filename) {
    std::ofstream output;
    bool success = false;
    do {
        std::cout << "=== Adding new person ===";
        success = true;
    } while (!success);
}