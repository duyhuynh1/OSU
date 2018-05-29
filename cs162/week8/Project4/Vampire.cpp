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
Vampire::Vampire(std::string name) : Character(name, "Vampire", 1, 18) {
    initDice(1, 12, 1, 6);
}

/**
 *  Vampires defend function has a unique aditional ability called
 *  "Charm" (Vampires can charm an opponent into not attacking. For 
 *  a given attack there is a 50% chance that their opponent does 
 *  not actually attack them).
 *  Note: If the Vampire’s “charm” ability activates when 
 *  Medusa uses “glare”, the Vampire’s charm trumps Medusa’s glare.
 *  @param damage An integer depicting the raw amount of damage inflicted
 */
void Vampire::defend(int &damage) {
    abilityActivated = false;   // reset abilityActivated status
    defensePoints = 0;          // reset defensePoints
    // 50% chance of mitigating damage, rolls either 0 = false OR 1 = true
    if (rand() % 2) {
        abilityActivated = true;
        std::cout << "[ABILITY]: Charm activated!\n";
    }
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    if (damage == -1) { // Handles Medusa's Glare attack
        if (abilityActivated) {
            totalDamage = 0;
        } else {
            totalDamage = strengthPoints;
            strengthPoints = 0;
        }
    } else if (abilityActivated || damage <= (defensePoints + armorPoints)) {
        totalDamage = 0;
    } else {
        totalDamage = damage - defensePoints - armorPoints;
        strengthPoints -= totalDamage;
    }
}