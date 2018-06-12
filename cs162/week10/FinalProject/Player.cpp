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
                    yPos--;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 2:
                if (current->right != nullptr) {
                    current = current->right;
                    xPos++;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 3:
                if (current->left != nullptr) {
                    current = current->left;
                    xPos--;
                    success = true;
                } else {
                    std::cout << moveError;
                }
                break;
            case 4:
                if (current->bottom != nullptr) {
                    current = current->bottom;
                    yPos++;
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
    // TODO: Add "LockedDoorSpace" logic
    if (spaceType == "LockedDoorSpace") {
        if (!current->isLocked()) {
            std::cout << "[I]: Door is unlocked.\n";
        } else if (current->isLocked()) {
            if (inventory[0] == "door key") {
                current->trigger();
                inventory[0] = " ";
                std::cout << "[I]: Used the key to unlock the door\n";
            } else {
                std::cout << "[I]: The door is locked. Looks like it requires a key\n";
            }
        }
    }
}

/**
 *  Display the Player's current inventory
 */
void Player::showInventory() { std::cout << "Inventory: { " << inventory[0] << " };" << std::endl; }

/**
 *  Display the Player's current position on the Map
 */
void Player::showPosition() {
    std::cout << std::string(50,'-') << std::endl;
    std::cout << "Location\n";
    if (current->top != nullptr &&
        current->left != nullptr) {
        std::cout << "    ";
        showSpace(current->top);
        std::cout << "\n";
        std::cout << "     |\n";
    } else if (current->top != nullptr) {
        showSpace(current->top);
        std::cout << "\n";
        std::cout << " | \n";
    }
    if (current->left != nullptr) {
        showSpace(current->left);
        std::cout << "-";
    }
    // Player's position is absolute
    std::cout << "[*]";
    if (current->right != nullptr) {
        std::cout << "-";
        showSpace(current->right);
        std::cout << "\n";
    } else {
        std::cout << "\n";
    }
    if (current->bottom != nullptr &&
        current->left != nullptr) {
        std::cout << "     |\n";
        std::cout << "    ";
        showSpace(current->bottom);
        std::cout << "\n";
    } else if (current->bottom != nullptr) {
        std::cout << " | \n";
        showSpace(current->bottom);
        std::cout << "\n";
    }
    std::cout << std::string(50,'-');
    std::cout << "\n";
}

void Player::showSpace(Space* space) {
    if (space->getType() == "Space") {
        std::cout << "[ ]";
    }
    if (space->getType() == "ItemSpace") {
        std::cout << "[□]";
    }
    if (space->getType() == "PressurePlateSpace") {
        std::cout << "[▃]";
    }
    if (space->getType() == "LockedItemSpace") {
        std::cout << "[▣]";
    }
    if (space->getType() == "LockedDoorSpace") {
        std::cout << "[╏]";
    }
}