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
Character::Character(std::string type, SpecialAbilities ability,
                     int armor, int strength) {
    characterType = type;
    characterAbility = ability;
	armorPoints = armor;
	strengthPoints = strength;
}

/**
 *  Character Class default virtual destructor
 */
Character::~Character() {
    // std::cout << "[D]: Character::~Character() called\n";   // REMOVE
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
    // std::cout << "[D]: Character::attack() called\n";    // REMOVE
    int attackPoints = 0;   // Reset attackPoints
    for (int i = 0; i < attackPowerDice.size(); i++) {
        attackPoints += attackPowerDice[i]->roll();
    }
    std::cout << "[Attack Roll]: - " << attackPoints << std::endl;
    otherPlayer->defend(attackPoints);
    turns++;
}

/**
 *  Character's basic defend function takes into account the
 *  character's defense and armor. The total amount is deducted
 *  from the Character's strength points
 */
void Character::defend(int &damage) {
    // std::cout << "[D]: Character::defend called()\n";   // REMOVE
    defensePoints = 0;  // Reset defensePoints
    for (int i = 0; i < defensePowerDice.size(); i++) {
        defensePoints += defensePowerDice[i]->roll();
    }
    std::cout << "[Defend Roll]: + " << defensePoints << std::endl;
    if (damage == -1) {
        std::cout << "[D]: Defender object receives Medusa's GLARE" << std::endl; 
        strengthPoints = 0;
    } else if (damage <= (defensePoints + armorPoints)) {   // Damage mitigated
        return;
    } else {
        strengthPoints -= damage - defensePoints - armorPoints;    
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
        std::cout << "Player has died...\n";
        return false;
    }
}

/**
 *  Return the Character's Type
 */
std::string Character::getCharacterType() const { return characterType; }

/**
 *  Return the Character's armor points
 */
int Character::getArmorPoints() const { return armorPoints; }

/**
 *  Return the Character's strength points
 */
int Character::getStrengthPoints() const { return strengthPoints; }