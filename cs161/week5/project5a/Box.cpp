/*********************************************************************
** Author: Tony Huynh
** Date: 2/07/2018
** Description: Box class implementation file
*********************************************************************/
// #include <iostream>
#include <cmath>
#include "Box.hpp"

/** Box object default constructor. Sets height = width = length = 1 */
Box::Box() {
    setHeight(1.0);
    setWidth(1.0);
    setLength(1.0);
}

/** Box object constructor with 3 doubles args */
Box::Box(double h, double w, double l) {
    setHeight(h);
    setWidth(w);
    setLength(l);
}

/** Box object destructor */
// Box::~Box() {
//     std::cout << "Destructing object" << std::endl;
// }

/** Set the height dimension of the Box object. */
void Box::setHeight(double h) {
    height = h;
}

/** Set the width dimension of the Box object. */
void Box::setWidth(double w) {
    width = w;
}

/** Set the length dimension of the Box object. */
void Box::setLength(double l) {
    length = l;
}

/**
    Returns the volume of a Box object.
    Volume Formula = height * width * length
*/
double Box::calcVolume() { 
    return height * width * length; 
}

/**
    Returns the surface area of a Box object.
    Surface Area Formula = 2 * (width * height) + 2 (length * height)
    + 2 * (width * length)
*/
double Box::calcSurfaceArea() {
    return 2 * (width * height) + 2 * (length * height) + 2 * (width * length);
}

/** Returns a Box object's member variable values. */
// void Box::toString() {
//     std::cout << "Box{ "
//               << "height: " << height << "; "
//               << "width: " << width << "; "
//               << "length: " << length
//               << " }" << std::endl;
// }