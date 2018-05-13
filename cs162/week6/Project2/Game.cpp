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
        std::cout << std::setw(17) << std::right << "[" 
                  << p1->getCharacterType() << "]<="
                  << std::string(16, ' ')
                  << std::setw(17) << std::left << "  ["
                  << p2->getCharacterType() << "]" << std::endl;
        std::cout << std::string(50, '-') << std::endl;
        std::cout << "[Armor]: " << p1->getArmorPoints()
                  << std::string(14, ' ') << "|" << std::string(14, ' ')
                  << "[Armor]: " << p2->getArmorPoints() << "\n"
                  << "[Strength]: " << p1->getStrengthPoints()
                  << std::string(10, ' ') << "|" << std::string(10, ' ')
                  << "[Strength]: " << p2->getStrengthPoints() << "\n"
                  << "[Atk]: " << p1->getAttackPoints()
                  << std::string(14, ' ') << "|" << std::string(14, ' ')
                  << "[Def]: " << p2->getDefensePoints() << "\n"
                  << std::string(50, '-') << "\n"
                  << "[Total Damage]: " << p2->getTotalDamage() << std::endl;
    } else {
        std::cout << "[" << p1->getCharacterType() << "]  "
                  << std::string(12, ' ') << "|" << std::string(11, ' ')
                  << std::setw(3) << std::left << "=>["
                  << p2->getCharacterType() << "]\n"
                  << std::string(50, '-') << "\n"
                  << "[Armor]: " << p1->getArmorPoints()
                  << std::string(14, ' ') << "|" << std::string(14, ' ')
                  << "[Armor]: " << p2->getArmorPoints() << "\n"
                  << "[Strength]: " << p1->getStrengthPoints()
                  << std::string(10, ' ') << "|" << std::string(10, ' ')
                  << "[Strength]: " << p2->getStrengthPoints() << "\n"
                  << "[Def]: " << p1->getDefensePoints()
                  << std::string(14, ' ') << "|" << std::string(14, ' ')
                  << "[Atk]: " << p2->getAttackPoints() << "\n"
                  << std::string(50, '-') << "\n"
                  << "[Total Damage]: " << p1->getTotalDamage() << std::endl;
    }
    std::cout << std::string(50, '-') << std::endl;
}