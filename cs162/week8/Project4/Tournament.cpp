/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Tournament class is used to control the flow of the
** Tournament. Controls include the players in queue and combat info.
*********************************************************************/
#include "Tournament.hpp"

/**
 *  Initialize the Queue
 */
void Tournament::init(Queue *teamA, Queue *teamB, Queue *loserPile) {
    this->teamA = teamA;
    this->teamB = teamB;
    this->loserPile = loserPile;
}

/**
 *  After player lineup selection is complete proceed with game.
 */
void Tournament::start() {
    teamAPoints = 0;
    teamBPoints = 0;
    bool gameOver = false;
    do {
        if (!teamA->isEmpty() && !teamB->isEmpty()) {
            std::cout << std::string(50, '=') << std::endl;
            std::cout << "Current Queue\n";
            std::cout << std::string(50, '=') << std::endl;
            getQueueInfo();
            attacker = teamA->getFront();
            p1 = attacker;
            defender = teamB->getFront();
            p2 = defender;
            while (attacker->isAlive() && defender->isAlive()) {
                rounds++;
                std::cout << "\n[ROUND#]: " << rounds << std::endl;
                attacker->attack(defender);
                getInfo();
                if (!(defender->isAlive())) {
                    std::cout << "\n[FINAL RESULTS]" << std::endl;
                    getInfo();
                    break;
                }
                swapRole(attacker, defender);
            }
            setupNextFight();
        } else {
            std::cout << std::string(50, '=') << std::endl;
            std::cout << "Tournament Results\n";
            std::cout << std::string(50, '=') << std::endl;
            getQueueInfo();
            std::cout << std::string(50, '*') << std::endl;
            std::cout << "Tournament Score\n";
            std::cout << std::string(50, '*') << std::endl;
            std::cout << "Team A: " << teamAPoints << " -vs- ";
            std::cout << "Team B: " << teamBPoints << std::endl;
            if (teamAPoints == teamBPoints) {
                std::cout << "[GAME RESULT]: TIE\n";
            } else if (teamAPoints > teamBPoints) {
                std::cout << "[GAME RESULT]: TEAM A WON FANTASY COMBAT TOURNAMENT\n";
            } else {
                std::cout << "[GAME RESULT]: TEAM B WON FANTASY COMBAT TOURNAMENT\n";
            }
            gameOver = true;
        }
    } while (!gameOver);
}

/**
 *  Swaps the attacker and defender roles of the two Characters
 */
void Tournament::swapRole(Character *p1, Character *p2) {
    Character *temp = p1;
    attacker = p2;
    defender = temp;
}

/**
 *  Puts the fighters into the appropriate containers.
 *  The winner of the match is pushed to the back of the Queue and is healed.
 *  The loser of the match is pushed to the front of the loser pile.
 */
void Tournament::setupNextFight() {
    // Determines who won the round
    if (teamA->getFront()->isAlive()){
        std::cout << "[ANOUNCEMENT]: Team A " << teamA->getFront()->getCharacterName() << " WON!\n";
        teamAPoints += 1;
        teamA->getFront()->recoverStrengthPoints(); // Activate recovery
        teamA->moveFrontToBack();   // Move Team A's front player to the back of queue
        teamB->moveFrontToFrontOf(loserPile);   // If Team A won, move the front player to the loser pile
    } else {
        std::cout << "[ANOUNCEMENT]: Team B " << teamB->getFront()->getCharacterName() << " WON!\n";
        teamBPoints += 1;
        teamB->getFront()->recoverStrengthPoints();
        teamB->moveFrontToBack();   // Move Team B's front player to the back of queue
        teamA->moveFrontToFrontOf(loserPile);   // If Team B won, move the front player to the loser pile
    }
}

/**
 *  Display the current attacking Character
 */
void Tournament::getInfo() {
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

/**
 *  Print's out the current team lineup
 */
void Tournament::getQueueInfo() {
    std::cout << "Team A Lineup\n";
    std::cout << std::string(50, '-') << std::endl;
    if (!teamA->isEmpty()) {
        teamA->printQueue();
    } else {
        std::cout << "[INFO]: Queue is empty...\n";
    }
    std::cout << "\nTeam B Lineup\n";
    std::cout << std::string(50, '-') << std::endl;
    if (!teamB->isEmpty()) {
        teamB->printQueue();
    } else {
        std::cout << "[INFO]: Queue is empty...\n";
    }
    std::cout << "\nLoser Pile\n";
    std::cout << std::string(50, '-') << std::endl;
    if (!loserPile->isEmpty()) {
        loserPile->printQueue();
    } else {
        std::cout << "[INFO]: Queue is empty...\n";
    }
}