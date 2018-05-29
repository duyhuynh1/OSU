/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Blue Men class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Mob".
*********************************************************************/
#include "BlueMen.hpp"

/**
 *  Blue Men class default constructor
 *  attack   = 2d10 {min: 2 max: 20}
 *  defense  = 3d6  {min: 3 max: 18}
 *  armor    = 3
 *  strength = 12 *Mob
 */
BlueMen::BlueMen(std::string name) : Character(name, "Blue Men", 3, 12) {
    initDice(2, 10, 3, 6);
}

/**
 *  The Bluemen's defense function will reduce the number of defensePowerDice
 *  when the following conditions are true:
 *  - strength <= 12 && >= 9   -> 3d6
 *  - strength <= 8 && >= 5    -> 2d6
 *  - strength <= 4            -> 1d6
 */
void BlueMen::defend(int &damage) {
    defensePoints = 0;  // Reset defensePoints
    totalDamage = 0;    // Reset totalDamage
    // Mob special ability implemented
    if (strengthPoints <= 8 && defensePowerDice.size() == 3) {
        std::cout << "[ABILITY]: Blue Men have 2/3 dice left\n";
        delete defensePowerDice.back();
        defensePowerDice.pop_back();
    } else if (strengthPoints <= 4 && defensePowerDice.size() == 2) {
        std::cout << "[ABILITY]: Blue Men have 1/3 dice left\n";
        delete defensePowerDice.back();
        defensePowerDice.pop_back();
    }
    // Defense dice rolls
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    // Handle Medusa's GLARE attack
    if (damage == -1) {
        totalDamage = strengthPoints;
        strengthPoints = 0;
    } else if (damage <= (defensePoints + armorPoints)) {
        totalDamage = 0;
    } else {
        totalDamage = damage - defensePoints - armorPoints;
        strengthPoints -= totalDamage;
    }
}