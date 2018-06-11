#include <iostream>
#include "Space.hpp"

/**
 *  Space class default constructor
 */
Space::Space() {
    std::string movePrompt = "1. ↑ (top)\n2. → (right)\n"
                             "3. ← (left)\n4. ↓ (down)\n=> ";
    Option option(movePrompt, 1, 4);
    mMenu.addOption(option);
}

Space::~Space() { std::cout << "Space destructor called\n"; }
/**
 *  Space class default constructor
 *  @param:
 */
Space::Space(std::string type) {
    this->type = type;
    std::string movePrompt = "1. ↑ (top)\n2. → (right)\n"
                             "3. ← (left)\n4. ↓ (down)\n=> ";
    Option option(movePrompt, 1, 4);
    mMenu.addOption(option);
}

/**
 *  Allows character to navigate to other connected Spaces
 */
int Space::getMovement() { return mMenu.getUnsignedInteger(0); }

/**
 *  Returns an item found at the space
 */
std::string Space::getItem() { return " "; }

/**
 *  Used to indicate if the space is empty
 */
bool Space::isEmpty() { return true; }

/**
 *  Used to indicate if the space is activated
 */
bool Space::isActivated() { return false; }

/**
 *  Used to trigger the Pressure Plate Space object
 */
void Space::trigger() { return; }

/**
 *  Used to indicate if the space is locked
 */
bool Space::isLocked() { return false; }
/**
 *  Return the type of space
 */
std::string Space::getType() { return type; }

/**
 *  Connects the calling space's top pointer to another Space object
 *  @param other - The Space object the calling Space will connect to
 */
void Space::topConnectToBottomOf(Space& other) { top = &other; }

/**
 *  Connects the calling space's bottom pointer to another Space object
 *  @param other - The Space object the calling Space will connect to
 */
void Space::bottomConnectToTopOf(Space& other) { bottom = &other; }

/**
 *  Connects the calling space's right pointer to another Space object
 *  @param other - The Space object the calling Space will connect to
 */
void Space::rightConnectToLeftOf(Space& other) { right = &other; }

/**
 *  Connects the calling space's left pointer to another Space object
 *  @param other - The Space object the calling Space will connect to
 */
void Space::leftConnectToRightOf(Space& other) { left = &other; }