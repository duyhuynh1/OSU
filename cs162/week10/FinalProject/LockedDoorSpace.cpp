#include "LockedDoorSpace.hpp"

/**
 *  Locked Door Space class default constructor
 */
LockedDoorSpace::LockedDoorSpace() : Space("LockedDoorSpace") {}

/**
 *  Returns true if the door is locked. Otherwise false.
 */
bool LockedDoorSpace::isLocked() { return (locked) ? true : false; }

/**
 *  Only gets triggered if the user has a "door key"
 */
void LockedDoorSpace::trigger() { locked = false; }