/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Harry Potter class is a derived Character class. It
** has atributes such as attack, defense, armor, strength, and has
** the special ability "Hogwart".
*********************************************************************/
#include "HarryPotter.hpp"

/**
 *  Harry Potter class default constructor
 *  attack   = 2d6 {min: 2 max: 12}
 *  defense  = 2d6 {min: 2 max: 12}
 *  armor    = 0
 *  strength = 10/20 * Hogwarts
 */
HarryPotter::HarryPotter() : Character ("HarryPotter", HOGWARTS, 0, 10) {
    initDice(2, 6, 2, 6);
}

/**
 *  Harry Potter's defend function is modifided to exhibit the following
 *  special effects of the Hogwarts ability.
 *  "Hogwarts": If Harry Potter's strength reaches 0 or below, he 
 *  immediately recovers and his total strength becomes 20. If he 
 *  were to die again, then he’s dead.
 *  Note: If Medusa uses “glare” on Harry Potter on his first life, 
 *  then Harry Potter comes back to life after using “hogwarts”.
 */
void HarryPotter::defend(int &damage) {
    defensePoints = 0;  // Reset the defense value
    if (damage == -1) {
        if (wasResurrected == false) {
            std::cout << "[D]: GLARE true, HOGWARTS not used, harry is revived\n";
            wasResurrected = true;
            strengthPoints = 20;
            return;
        } else {
            std::cout << "[D]: GLARE true, HOGWARTS used, harry dies...\n";
            strengthPoints = 0;
            return;
        }
    }
    
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    std::cout << "[Defend Roll]: " << defensePoints << std::endl;
    if (damage <= (defensePoints + armorPoints)) {
        std::cout << "[D]: damage mitigated\n";
        return;
    } else {
        strengthPoints -= damage - defensePoints - armorPoints;
    }
}

/**
 *  Returns TRUE if the Hogwarts affect 
 */