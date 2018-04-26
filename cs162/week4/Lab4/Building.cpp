/*********************************************************************
** Program name: OSU Information System
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Building Class represents a Building object that 
** contains the property name, address, and square footage.
*********************************************************************/
#include "Building.hpp"

/**
 *  Building class default constructor
 */
Building::Building(std::string name, std::string address, int size) {
    this->name = name;
    this->address = address;
    this->size = size;
}

/**
 *  Return the Building's name
 */
std::string Building::getName() const { return name; }

/**
 *  Return the Building's address
 */
std::string Building::getAddress() const { return address; }

/**
 *  Return the Building's size in square feet
 */
int Building::getSize() const { return size; }