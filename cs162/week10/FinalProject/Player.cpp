#include "Player.hpp"
/**
 *  Player class default constructor
 *  @param startSpace - The space object the character is currently at
 */
Player::Player(Space& startSpace) { current = &startSpace; }

/**
 *  Player moves to the available Spaces 
 */
void Player::move() {
    std::string moveError = "[!] Can't seem to go that direction...\n";
    bool success = false;
    while (!success) {
        switch (current->getMovement()) {
            case 1:
                if (current->top != nullptr) {
                    current = current->top;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 2:
                if (current->right != nullptr) {
                    current = current->right;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 3:
                if (current->left != nullptr) {
                    current = current->left;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 4:
                if (current->bottom != nullptr) {
                    current = current->bottom;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
        }
    }
}

/**
 *  Activates the space special event
 */
void Player::inspectSpace() {
    std::string spaceType = current->getType();
    if (spaceType == "ItemSpace") {
        if (current->isEmpty()) {
            std::cout << "[I]: The chest is empty\n";
        } else {
            if (inventory[0] == " ") {    // Add item to Player's inventory
                inventory[0] = current->getItem();
                std::cout << "[I]: Added a " << inventory[0] << " to the inventory\n"; 
            } else {
                std::cout << "[W]: Inventory is full\n";
            }
        }
    }
    if (spaceType == "PressurePlateSpace") {
        if (inventory[0] == "rock") {
            if (current->isActivated() == false) {
                current->trigger();
                inventory[0] = " "; // Used up the rock
                std::cout << "[I]: Used the rock to hold down the pressure plate\n";
            } else {
                std::cout << "[I]: Pressure plate was already activated\n";
            }
        } else {
            std::cout << "[I]: Need something heavy like a "
                         "\'rock\'' to hold the plate down\n";
        }
    }
    if (spaceType == "LockedItemSpace") {
        if (current->isEmpty()) {
            std::cout << "[I]: The chest is empty\n";
        } else if (current->isLocked() && inventory[0] == "key") {
            inventory[0] = " "; // Used up key
            std::cout << "[I]: Used the key to open the chest\n";
            current->trigger();
            inventory[0] = current->getItem();
            std::cout << "[I]: Added a " << inventory[0] << " to the inventory\n";
        } else {
            std::cout << "[I]: Looks like the chest needs a \'key\' in order to open\n";
        }
    }
}

/**
 *  Display the Player's current inventory
 */
void Player::showInventory() { std::cout << "Inventory: { " << inventory[0] << " };" << std::endl; }