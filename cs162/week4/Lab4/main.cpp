/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The driver program that allows the user to navigate
** through the OSU Information System.
*********************************************************************/
#include <iostream>
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "University.hpp"
#include "Menu.hpp"
#include "Option.hpp"

int main() {
    // TODO: Write a queryDatabase() function to read in Building and Person objects
    // TEST REMOVE v
    Person * person1 = new Student("Tony", 25, 3.99);
    Person * person2 = new Instructor("Bob", 43, 4.89);
    Person * person3 = new Student("John", 24, 3.75);

    University mUniversity;
    mUniversity.addPeople(person1);
    mUniversity.addPeople(person2);
    mUniversity.addPeople(person3);
    // TEST REMOVE ^
    std::string mainMenuPrompt = "1. Show all building information\n"
                                 "2. Show all people information\n"
                                 "3. Choose a person to do work\n"
                                 "4. Exit program\n> ";
    // TODO: Need a menu that queries the name of all the people name
    // std::string doWorkPrompt = "Select a person to do work: ";

    Option * option1 = new Option(mainMenuPrompt, 1, 4);
    // Option * option2 = new Option(doWorkPrompt, );

    Menu mMenu;
    mMenu.addOption(option1);       // Index 0
    // mMenu.addOption(option2);
    std::cout << "===============================================\n"
              << "OSU INFORMATION SYSTEM\n"
              << "===============================================\n";
    int selection = mMenu.getValue(0);

    switch (selection) {
        case 1:
            std::cout << "Querying all building information..." << std::endl;
            break;
        case 2:
            std::cout << "Querying all people information..." << std::endl;
            mUniversity.getPeopleInfo();
            break;
        case 3:
            std::cout << "[D]: Choose a person to work menu" << std::endl;
            break;
        case 4:
            std::cout << ">>> Exit Program <<<" << std::endl;
            break;
    }

    delete option1;
    // delete option2;

    // ------
    // Person * person1 = new Person("Tony", 25);
    // Person * person2 = new Student("Bob", 21, 4.0);
    // Person * person3 = new Instructor("Ron", 45, 4.85);
    // Building * building1 = new Building("Kelley Engineering Center",
    //                                     "110 SW PARK TERRACE CORVALLIS, OR 97331",
    //                                     152166);
    // person1->do_work();
    // person2->do_work();
    // person3->do_work();
    
    // std::cout << building1->getName() << std::endl;
    // std::cout << building1->getAddress() << std::endl;
    // std::cout << building1->getSize() << std::endl;

    // Student * student1 = dynamic_cast<Student *>(person2);
    // Instructor * instructor1 = dynamic_cast<Instructor *>(person3);
    // if (student1 != NULL) {
    //     std::cout << "Student GPA = " << student1->getGPA() << std::endl;
    // }
    // if (instructor1 != NULL) {
    //     std::cout << "Instructor rating = " << instructor1->getRating() << std::endl;
    // }

    // delete person1;
    // delete person2;

    return 0;
}