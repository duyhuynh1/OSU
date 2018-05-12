/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Vampire class is a derived Character class. It 
** has attributes such as attack, defense, armor, strength, and has 
** the special ability "Charm".
*********************************************************************/
#include "Vampire.hpp"

/**
 *  Vampire class default constructor
 *  attack   = 1d12 {min: 1, max: 12}
 *  defense  = 1d6  {min: 1, max: 12} *CHARM
 *  armor    = 1
 *  strength = 12
 */
Vampire::Vampire() : Character("Vampire", CHARM, 1, 18) {
    initDice(1, 12, 1, 6);
}

/**
 *  Vampires defend function has a unique aditional ability called
 *  "Charm" (Vampires can charm an opponent into not attacking. For 
 *  a given attack there is a 50% chance that their opponent does 
 *  not actually attack them).
 *  Note: If the Vampire’s “charm” ability activates when 
 *  Medusa uses “glare”, the Vampire’s charm trumps Medusa’s glare.
 */
void Vampire::defend(int &damage) {
    // std::cout << "[D]: Vampire::defend() called\n"; // REMOVE
    defensePoints = 0;
    // 50% chance of mitigating damage, rolls either 0 or 1
    int charmActivate = rand() % 2;     // 0 = false, 1 = true
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    std::cout << "[Defend Roll]: + " << defensePoints << std::endl;
    std::cout << "charmActivate: " << charmActivate << std::endl;
    std::cout << "damage: " << damage << std::endl;
    // TODO: Need to redo logic
    if (damage == -1 && charmActivate == 0) {
        std::cout << "[D]: (1) GLARE true CHARM false\n";   // REMOVE
        strengthPoints = 0;
    } else if (damage == -1 && charmActivate == 1) {
        std::cout << "[D]: (2) GLARE true CHARM true\n";    // REMOVE
        return;
    } else if (charmActivate || damage <= (defensePoints + armorPoints)) {
        std::cout << "[D]: (3) GLARE false CHARM true OR damage less than defense\n";   // REMOVE
        return;
    } else {
        std::cout << "[D]: (4) GLARE false CHARM false\n";  // REMOVEs
        strengthPoints -= damage - defensePoints - armorPoints;
    }
}