/*********************************************************************
** Program name: Dice War Game
** Author: Tony Huynh
** Date: 04/22/2018
** Description: The Game class implements all the rules required to 
** play the Dice War Game.
*********************************************************************/
#include "Game.hpp"

/**
 *	Game default constructor
 *	@param rounds Is the number of rounds the game will have
 *	@param p1 is a pointer to a Player object
 *	@param p2 is a pointer to a Player ojbect
 */
Game::Game(int rounds, Player * p1, Player * p2) {
    this->rounds = rounds;
    contestants.push_back(p1);
    contestants.push_back(p2);
}

/**
 *	Starts the game by invoking each Player's roll function
 *	The player who rolls a higher number will recieve a point.
 *	If both players roll the same number then neither recieve a point.
 *	Points are tallied up per round.
 */
void Game::start() {
	std::cout << "====================" << std::endl;
	int currentRound = 1;
    while (currentRound <= rounds) {
		std::cout << "Round #" << currentRound << std::endl;
		std::cout << "--------------------" << std::endl;
    	for (int i = 0; i < contestants.size(); ++i) {
    		playerScore[i] = contestants[i]->rollDie();
    		std::cout << contestants[i]->getName() << " rolled a "
    				  << playerScore[i] << " with a "
    				  << contestants[i]->getDieNumberOfSides() << " sided "
    				  << contestants[i]->getDieType() << std::endl;
    	}
    	if (playerScore[0] > playerScore[1]) {
    		std::cout << "> Player1 +1 point <" << std::endl;
    		contestants[0]->addPoints();
    	} else if (playerScore[0] < playerScore[1]) {
    		std::cout << "> Player2 +1 point <" << std::endl;
    		contestants[1]->addPoints();
    	} else if (playerScore[0] == playerScore[1]) {
    		std::cout << "> Draw! No points awarded <" << std::endl;
    	}
    	std::cout << "Current score [ Player1 = " << contestants[0]->getPoints()
    			  << " : Player2 = " << contestants[1]->getPoints() << " ]"
    			  << std::endl;
    	std::cout << "--------------------" << std::endl;
    	currentRound++;
    }
    displayResults();
}

/**
 *	Displays the Game's final results and indicates which player won
 */
void Game::displayResults() {
	int p1FinalScore = contestants[0]->getPoints();
	int p2FinalScore = contestants[1]->getPoints();
	std::cout << "====================\n"
			  << "FINAL SCORE\n"
			  << "====================\n";
	if (p1FinalScore > p2FinalScore) {
		std::cout << contestants[0]->getName() << " WINS!" << std::endl;
	} else if (p1FinalScore < p2FinalScore) {
		std::cout << contestants[1]->getName() << " WINS!" << std::endl;
	} else {
		std::cout << "TIE GAME!!!" << std::endl;
	}
	std::cout << ">>> EXITING GAME <<<" << std::endl;
}