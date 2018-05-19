/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The game class is used to control the flow of the game.
** Controls include the players in queue and combat info.
*********************************************************************/
#include "Game.hpp"

void Game::init(Character * p1, Character * p2) {
    this->p1 = p1;
    this->p2 = p2;
    attacker = p1;
    defender = p2;
}

void Game::start() {
    while (attacker->isAlive() && defender->isAlive()) {
        rounds++;
        std::cout << "\n[ROUND#]: " << rounds << std::endl;
        attacker->attack(defender);
        getInfo();
        if (!(defender->isAlive())) {
            std::cout << "\n[FINAL RESULTS]" << std::endl;
            // TODO: Display the player who won...
            getInfo();
            return;
        }
        swapRole(attacker, defender);
    }
}

/**
 *  Swaps the attacker and defender roles of the two Characters
 */
void Game::swapRole(Character *p1, Character *p2) {
    Character *temp = p1;
    attacker = p2;
    defender = temp;
}

/**
 *  Display the current attacking Character
 */
void Game::getInfo() {
    std::cout << std::string(50, '-') << std::endl;
    if (p1 == attacker) {
        std::cout << "[" 
                  << p1->getCharacterType() << "]<=";
        std::cout << std::string(16, ' ');
        std::cout << std::setw(7) << std::right << "  ["
                  << p2->getCharacterType() << "]" << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "[Armor]: " << p1->getArmorPoints()
                  << std::string(30, ' ')
                  << p2->getArmorPoints() << " :[Armor]\n"
                  << "[Strength]: " << p1->getStrengthPoints()
                  << std::string(23, ' ')
                  << p2->getStrengthPoints() << " :[Strength]\n"
                  << "[Atk]: " << p1->getAttackPoints()
                  << std::string(34, ' ')
                  << p2->getDefensePoints() << " :[Def]\n"
                  << std::string(50, '-') << "\n"
                  << "[Total Damage]: " << p2->getTotalDamage() << std::endl;
    } else {
        std::cout << "[" 
                  << p1->getCharacterType() << "]  ";
        std::cout << std::string(16, ' ');
        std::cout << std::setw(7) << std::right << "=>["
                  << p2->getCharacterType() << "]" << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "[Armor]: " << p1->getArmorPoints()
                  << std::string(30, ' ')
                  << p2->getArmorPoints() << " :[Armor]\n"
                  << "[Strength]: " << p1->getStrengthPoints()
                  << std::string(23, ' ')
                  << p2->getStrengthPoints() << " :[Strength]\n"
                  << "[Def]: " << p1->getDefensePoints()
                  << std::string(34, ' ')
                  << p2->getAttackPoints() << " :[Atk]\n"
                  << std::string(50, '-') << "\n"
                  << "[Total Damage]: " << p2->getTotalDamage() << std::endl;
    }
    std::cout << std::string(50, '-') << std::endl;
}