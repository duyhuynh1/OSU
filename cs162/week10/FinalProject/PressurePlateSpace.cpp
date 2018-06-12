#include <iostream>
#include "PressurePlateSpace.hpp"

PressurePlateSpace::PressurePlateSpace() : Space("PressurePlateSpace") {}

/**
 *
 */
bool PressurePlateSpace::isActivated() { return activated; }

/**
 *  
 */
void PressurePlateSpace::trigger() { activated = true; }