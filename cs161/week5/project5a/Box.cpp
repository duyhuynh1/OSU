#include <iostream>
#include <cmath>
#include <string>
#include "Box.hpp"

/** Box object default constructor. Sets height = width = length = 1 */
Box::Box() {
    setHeight(1.0);
    setWidth(1.0);
    setLength(1.0);
}

/** Box object constructor with 3 doubles args */
Box::Box(double heightIn, double widthIn, double lengthIn) {
    setHeight(heightIn);
    setWidth(widthIn);
    setLength(lengthIn);
}

/** Set the height dimension of the Box object. */
void Box::setHeight(double heightIn) {
    height = heightIn;
}

/** Set the width dimension of the Box object. */
void Box::setWidth(double widthIn) {
    width = widthIn;
}

/** Set the length dimension of the Box object. */
void Box::setLength(double lengthIn) {
    length = lengthIn;
}


/**
    Returns the volume of a Box object.
    Surface Area Formula = height * width * length

    @param Box Object
    @return The volume of the Box object.
*/
double calcVolume(Box box) {
    return box.height * box.width * box.length;
}

/**
    Returns the surface area of a Box object.
    Surface Area Formula = 2 * (width * height) + 2 (length * height)
    + 2 * (width * length)

    @param none required
    @return The surface area of the Box object.
*/
double calcSurfaceArea() {
    return 2 * (width * height) + 2 * (length * height) + 2 * (width * length);
}

/**
    Returns a string representation of the Box object.

    @return All member variables values are displayed as string.
*/
std::string Box::toString() {
    std::cout << "Box( " << std::endl;
    std::cout << "\theight = " << height << std::endl;
    std::cout << "\twidth = " << width << std::endl;
    std::cout << "\tlength = " << length << std::endl;
    std::cout << ")" << std::endl;
}