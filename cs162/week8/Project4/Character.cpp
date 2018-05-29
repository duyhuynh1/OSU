/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The character class is the base class for all other 
** types of characters in this combat game. Each characters has the
** following attributes such as attack, defense, armor, and strength.
*********************************************************************/
#include "Character.hpp"

/**
 *  Character Class default constructor that initializes the character's
 *  attack, defense, armor, and strength stats
 *  @param armor An integer depicting the character's armor stats
 *  @param strength An integer depicting the character's strength stats
 */
Character::Character(std::string name, std::string type, int armor, int strength) {
    this->name = name;
    characterType = type;
	armorPoints = armor;
	strengthPoints = maxStrengthPoints = strength;
}

/**
 *  Character Class default virtual destructor
 */
Character::~Character() {
    for (int i = 0; i < attackPowerDice.size(); i++) {
        if (attackPowerDice[i] != nullptr) {
            delete attackPowerDice[i];    
        }
    }
    for (int i = 0; i < defensePowerDice.size(); i++) {
        if (defensePowerDice[i] != nullptr) {
            delete defensePowerDice[i];
        }
    }
}

/**
 *  Virtual function initDice generates the Attack and Defense Dice
 *  object used to determine a Character's Attack and Defense power
 *  @param nAtkDice An integer depicting the number of dice for attack
 *  @param nAtkDiceSides An integer depicting the number of sides for attack Dice
 *  @param nDefDice An integer depicting the number of dice for defense
 *  @param nDefDiceSides An integer depicting the number of sides for defense Dice
 */
void Character::initDice(int nAtkDice, int nAtkDiceSides,
                         int nDefDice, int nDefDiceSides) {
    // Initialize Attack Dice
    for (int i = 0; i < nAtkDice; i++) {
        attackPowerDice.push_back(new Dice(nAtkDiceSides));    
    }
    // Initialize Defense Dice
    for (int i = 0; i < nDefDice; i++) {
        defensePowerDice.push_back(new Dice(nDefDiceSides));
    }
}

/**
 *  Character's basic attack function
 */
void Character::attack(Character *otherPlayer) {
    attackPoints = 0;   // Reset attackPoints
    for (int i = 0; i < attackPowerDice.size(); i++) {
        attackPoints += attackPowerDice[i]->roll();
    }
    otherPlayer->defend(attackPoints);
}

/**
 *  Character's basic defend function takes into account the
 *  character's defense and armor. The total amount is deducted
 *  from the Character's strength points
 */
void Character::defend(int &damage) {
    totalDamage = 0;
    defensePoints = 0;  // Reset defensePoints
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    if (damage == -1) {
        std::cout << "[ABILITY ACTIVATED]: GLARE" << std::endl;
        strengthPoints = 0;
    } else if (damage <= (defensePoints + armorPoints)) {   // Damage mitigated
        totalDamage = 0;
        return;
    } else {
        totalDamage = damage - defensePoints - armorPoints;
        strengthPoints -= totalDamage;
    }
}

/**
 *  Returns TRUE if character is alive. Otherwise FALSE.
 *  Character is not alive if strengthPoints <= 0.
 */
bool Character::isAlive() {
    if (strengthPoints > 0) {
        return true;
    } else {
        std::cout << "[INFO]: Player has died...\n";
        return false;
    }
}

/**
 *  Return the Character's Info
 */
void Character::getCharacterInfo() const {
    std::cout << "[" << getCharacterName() << "]|"
              << "[" << getCharacterType() << "]|"
              << "[Strength Points: " << getStrengthPoints() << "]|"
              << "[Armor Points: " << getArmorPoints() << "]\n";
}

/**
 *  Return the Character's name
 */
std::string Character::getCharacterName() const { return name; }

/**
 *  Return the Character's Type
 */
std::string Character::getCharacterType() const { return characterType; }

/**
 *  Restores the calling Character back to full health
 */
void Character::recoverStrengthPoints() {
    this->strengthPoints = maxStrengthPoints;
}

/**
 *  Return the total damage the Character has received
 */
int Character::getTotalDamage() const { return totalDamage; }

/**
 *  Return the Character's attack points
 */
int Character::getAttackPoints() const { return attackPoints; }

/**
 *  Return the Character's defense points
 */
int Character::getDefensePoints() const { return defensePoints; }

/**
 *  Return the Character's armor points
 */
int Character::getArmorPoints() const { return armorPoints; }

/**
 *  Return the Character's strength points
 */
int Character::getStrengthPoints() const { return strengthPoints; }

/**
 *  Return the Character's max strength points
 */
// int Character::getMaxStrengthPoints() const { return maxStrengthPoints; }