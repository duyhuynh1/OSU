/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The driver program that allows the user to navigate
** through the OSU Information System.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <climits>      // INT_MAX
#include <string>
#include <cstddef>      // std::size_t
#include <iomanip>      // std::setprecision
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "University.hpp"
#include "Menu.hpp"
#include "Option.hpp"

void loadBuildingInfo(University &, const std::string &);
void loadPeopleInfo(University &, const std::string &);
// void addNewBuildingInfo(University &, const std::string &);
void addNewPersonInfo(University &, const std::string &);
std::string validateStringInput(std::string, int);


int main() {
    // It would probably be best to store data in a separate directory.
    // But the requirements state that no extra directory should exist
    // const std::string buildingInfoFilename = "./data/BuildingInfo.txt";
    // const std::string peopleInfoFilename = "./data/PeopleInfo.txt";
    const std::string buildingInfoFilename = "BuildingInfo.txt";
    const std::string peopleInfoFilename = "PeopleInfo.txt";

    University mUniversity;
    loadBuildingInfo(mUniversity, buildingInfoFilename);
    loadPeopleInfo(mUniversity, peopleInfoFilename);

    std::string mainMenuPrompt = "1. Show all building information\n"
                                 "2. Show all people information\n"
                                 "3. Choose a person to do work\n"
                                 "4. Add new person\n"
                                 "5. Exit program\n> ";
    std::string doWorkPrompt = "Select a person to do work (No.): ";

    Option * option1 = new Option(mainMenuPrompt, 1, 5);
    Option * option2 = new Option(doWorkPrompt, 1, mUniversity.getNumberOfPeople());
    Menu mMenu;
    mMenu.addOption(option1);       // Index 0
    mMenu.addOption(option2);       // Index 1

    bool exit = false;
    do {
        Option * option3 = new Option(doWorkPrompt, 1, mUniversity.getNumberOfPeople());
        std::cout << "===============================================\n"
                  <<  mUniversity.getName() << " Information System\n"
                  << "===============================================\n";
        int selection = mMenu.getValue(0);
        switch (selection) {
            case 1:
                mUniversity.getBuildingInfo();
                break;
            case 2:
                mUniversity.getPeopleInfo();
                break;
            case 3:
                mUniversity.getPeopleInfo();
                mMenu.addOption(option3);
                mUniversity.selectPersonToDoWork(mMenu.getValue(2));
                mMenu.removeOption(2);
                break;
            case 4:
                addNewPersonInfo(mUniversity, peopleInfoFilename);
                break;
            case 5:
                std::cout << ">>> Exit Program <<<" << std::endl;
                exit = true;
                break;
        }
        delete option3;
    } while (!exit);

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
 *  This is not part of the Extra Credit so it will be REMOVED
 *  Allows the user to add a new Building to the BuildingInfo.txt
 *  Request user for the Building's name, 
 */
// void addNewBuildingInfo(University &mUniversity, const std::string &filename) {
//     std::string name = "";
//     std::string address = "";
//     int size = 0;
//     Option * tmpOption = new Option("Please enter a size: ", 1, 250000);
//     std::ofstream output;
//     bool success = false;
//     do {
//         output.open(filename, std::ios_base::app);
//         if (output) {
//             std::cout << "=== Adding new building ===" << std::endl;
//             name = validateStringInput("Please enter name: ", 27); 
//             address = validateStringInput("Please enter address: ", 47);
//             size = tmpOption->getSelection();
//             // Update the University Object with new Building
//             mUniversity.addBuilding(new Building(name, address, size));
//             output << "\n" << name << "," << address << "," << size;
//             success = true;
//         }
//     } while (!success);
//     delete tmpOption;
// }

/**
 *  Allows the user to add a new Person to the PersonInfo.txt
 */
void addNewPersonInfo(University &mUniversity, const std::string &filename) {
    std::string promptGPA = "Please enter Student's GPA { 0.0 - 4.0 }: ";
    std::string promptRating = "Please enter Instructor's rating { 0.0 - 5.0 }: ";
    std::string name = "";
    int age = 0;
    float value = 0.0;
    Option * tmpOption1 = new Option("Please select type of Person.\n"
                                     "1. Student\n2. Instructor\n> ", 1, 2);
    Option * tmpOption2 = new Option("Please enter age { 18 - 100 }: ", 18, 100);
    Option * tmpOption3 = new Option(promptGPA, 0, 4);
    Option * tmpOption4 = new Option(promptRating, 0, 5);
    std::ofstream output;
    bool success = false;
    do {
        output.open(filename, std::ios_base::app);
        if (output) {
            std::cout << "=== Adding new person ===" << std::endl;
            switch (tmpOption1->getSelection()) {
                case 1:
                    name = validateStringInput("Please enter name: ", 23);
                    age = tmpOption2->getSelection();
                    value = tmpOption3->getUnsignedFloat();
                    mUniversity.addPeople(new Student(name, age, value));
                    output << "\nStudent" << "," << name << "," << age << "," << value;
                    break;
                case 2:
                    name = validateStringInput("Please enter name: ", 23);
                    age = tmpOption2->getSelection();
                    value = tmpOption4->getUnsignedFloat();
                    mUniversity.addPeople(new Instructor(name, age, value));
                    output << "\nInstructor" << "," << name << "," << age << "," << value;
                    break;
            }
            success = true;
        }
    } while (!success);

    output.close();
    delete tmpOption1;
    delete tmpOption2;
    delete tmpOption3;
    delete tmpOption4;
}

/**
 *  Validates the user's string input by checking that the string 
 *  is not empty and does not contain the ',' delimiter
 */
std::string validateStringInput(std::string prompt, int max) {
    std::string result;
    std::size_t found;
    bool success = false;
    std::cout << prompt;
    do {
        std::getline(std::cin, result);
        found = result.find_first_of(',');
        if (result.length() > 0 && found == std::string::npos &&
            result.length() <= max) {
            success = true;
        } else {
            std::cout << prompt;
        }
    } while (!success);
    return result;
}