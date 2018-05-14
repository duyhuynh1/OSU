/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Medusa class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Glare".
*********************************************************************/
#include "Medusa.hpp"

Medusa::Medusa() : Character("Medusa", 3, 8) {
    initDice(2, 6, 1, 6);
}

void Medusa::attack(Character *otherPlayer) {
    abilityActivated = false;   // Reset abilityActivated
    attackPoints = 0;           // Reset attackPoints
    for (int i = 0; i < attackPowerDice.size(); i++) {
        attackPoints += attackPowerDice[i]->roll();
    }
    if (attackPoints == 12) {
        abilityActivated = true;
        std::cout << "[ABILITY]: Glare activated!\n";
        attackPoints = -1;
    }
    otherPlayer->defend(attackPoints);
    if (attackPoints == -1) {
        attackPoints = 12;  // Save the value 12 dice roll
    }
}