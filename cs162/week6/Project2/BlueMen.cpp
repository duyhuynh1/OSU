/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Blue Men class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Mob".
*********************************************************************/
#include "BlueMen.hpp"

BlueMen::BlueMen() : Character("Blue Men", MOB, 3, 12) {
    initDice(2, 10, 3, 6);
}

void BlueMen::defend(int &damage) {
    // strength = 12    -> 3d6
    // strength = 8 - 5 -> 2d6
    // strength <= 4    -> 1d6
    defensePoints = 0;
    if (strengthPoints <= 8 && defensePowerDice.size() == 3) {
        // std::cout << "[D]: deleting a defensePowerDice 2 dice left\n";  // REMOVE
        delete defensePowerDice.back();
        // std::cout << "[D]: deleted back()\n";   // REMOVE
        defensePowerDice.pop_back();
    } else if (strengthPoints <= 4 && defensePowerDice.size() == 2) {
        // std::cout << "[D]: deleting a defensePowerDice 1 dice left\n";  // REMOVE
        delete defensePowerDice.back();
        // std::cout << "[D]: deleted back()\n";   // REMOVE
        defensePowerDice.pop_back();
    }
    std::cout << "[D]: number of defensePowerDice = " << defensePowerDice.size() << std::endl;
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    std::cout << "[Defend Roll]: + " << defensePoints << std::endl;
    if (damage == -1) {
        strengthPoints = 0;
    } else if (damage <= (defensePoints + armorPoints)) {
        return;
    } else {
        strengthPoints -= damage - defensePoints - armorPoints;
    }
}