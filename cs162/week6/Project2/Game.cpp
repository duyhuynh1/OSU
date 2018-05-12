/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The game class is used to control the flow of the game.
** Controls include the players in queue and combat info.
*********************************************************************/
#include "Game.hpp"

Game::~Game() { // REMOVE??
    // for (int i = 0; i < 2; i++) {
    //     if (player[i] != nullptr) {
    //         delete player[i];
    //     }
    // }
    // delete [] player;
}

void Game::init(Character * p1, Character * p2) {
    std::cout << "[D]: Game::init() called\n";
    this->p1 = p1;
    this->p2 = p2;
    attacker = p1;
    defender = p2;
}

void Game::start() {
    while (attacker->isAlive() && defender->isAlive()) {
        getInfo();
        attacker->attack(defender);
        if (!(defender->isAlive())) {
            std::cout << "[D]: Defender has died\n";
            return;
        }
        rounds++;
        swapRole(attacker, defender);
    }
}

/**
 *  Swaps the attacker and defender roles of the two Characters
 */
void Game::swapRole(Character *p1, Character *p2) {
    // std::cout << "[D]: Game::swapRole() called\n"; // REMOVE
    // std::cout << "p1 addr: " << p1 << std::endl;    // REMOVE
    // std::cout << "p2 addr: " << p2 << std::endl;    // REMOVE
    Character *temp = p1;
    attacker = p2;
    defender = temp;
    // std::cout << "p1 addr: " << p1 << std::endl;    // REMOVE
    // std::cout << "p2 addr: " << p2 << std::endl;    // REMOVE
}

/**
 *  Display the current attacking Character
 */
void Game::getInfo() {
    // std::cout << "[D]: Game::getInfo() called\n";  //REMOVE
    if (p1 == attacker) {
        std::cout << std::setw(2) << std::left << "*["
                  << p1->getCharacterType() << "]* { "
                  << "armor: " << p1->getArmorPoints() << " | "
                  << "strength: " << p1->getStrengthPoints() << " }";
        std::cout << " <VS> "
                  << std::setw(2) << std::left << " ["
                  << p2->getCharacterType() << "]  { "
                  << "armor: " << p2->getArmorPoints() << " | "
                  << "strength: " << p2->getStrengthPoints() << " }"
                  << std::endl;
    } else {
        std::cout << std::setw(2) << std::left << " ["
                  << p1->getCharacterType() << "]  { "
                  << "armor: " << p1->getArmorPoints() << " | "
                  << "strength: " << p1->getStrengthPoints() << " }";
        std::cout << " <VS> "
                  << std::setw(2) << std::left << "*["
                  << p2->getCharacterType() << "]* { "
                  << "armor: " << p2->getArmorPoints() << " | "
                  << "strength: " << p2->getStrengthPoints() << " }"
                  << std::endl;
    }
}