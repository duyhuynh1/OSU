/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Building Class stores the information of a 
** Building object which includes: name, address, and size (sqft)
*********************************************************************/
#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>

class Building {
    private:
        std::string name;
        std::string address;
        int size;
    public:
        Building(std::string, std::string, int);
        std::string getName() const;
        std::string getAddress() const;
        int getSize() const;
};
#endif  // BUILDING_HPP