#include "LockedItemSpace.hpp"

LockedItemSpace::LockedItemSpace(std::string item) : Space("LockedItemSpace") {
    this->item = item;
}

std::string LockedItemSpace::getItem() {
    if (isLocked() == false && isEmpty() == false) {
        numOfItems--;
        return item;
    } else {
        return " ";
    }
}

bool LockedItemSpace::isEmpty() { return (numOfItems == 0) ? true : false; }

bool LockedItemSpace::isLocked() { return (locked) ? true : false; }

void LockedItemSpace::trigger() { locked = false; }