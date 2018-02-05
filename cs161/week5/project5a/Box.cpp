#include <iostream>
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

// Note ~ after scope resolution operator
Box::~Box() {
    std::cout << "Deconstructing object" << std::endl;
}

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
    Surface Area Formula = height * width * length

    @param Box Object
    @return The volume of the Box object.
*/
double Box::calcVolume() {
    return height * width * length;
}

/**
    Returns the surface area of a Box object.
    Surface Area Formula = 2 * (width * height) + 2 (length * height)
    + 2 * (width * length)

    @param none required
    @return The surface area of the Box object.
*/
double Box::calcSurfaceArea() {
    return 2 * (width * height) + 2 * (length * height) + 2 * (width * length);
}

/**
    Returns a Box objec's member variable values.

    @return All member variables values are displayed.
*/
void Box::toString() {
    std::cout << "Box{ ";
    std::cout << "height: " << height << "; ";
    std::cout << "width: " << width << "; ";
    std::cout << "length: " << length;
    std::cout << " }" << std::endl;
}