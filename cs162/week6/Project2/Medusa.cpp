/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Medusa class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Glare".
*********************************************************************/
#include "Medusa.hpp"

Medusa::Medusa() : Character("Medusa", GLARE, 3, 8) {
    initDice(2, 6, 1, 6);
}

void Medusa::attack(Character *otherPlayer) {
    // std::cout << "[D]: Medusa::attack() called\n";   // REMOVE
    int attackPoints = 0;   // Reset attackPoints
    // attackPoints = 12;  // TESTING REMOVE
    for (int i = 0; i < attackPowerDice.size(); i++) {
        attackPoints += attackPowerDice[i]->roll();
    }
    std::cout << "[Attack Roll]: " << attackPoints << std::endl;
    if (attackPoints == 12) {
        attackPoints = -1;  // Should we use 0 instead?
    }
    std::cout << "[Attack Roll]: - " << attackPoints << std::endl;
    otherPlayer->defend(attackPoints);
    turns++;
}