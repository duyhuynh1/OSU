#include "Game.hpp"

Game::Game(int rounds) {
    this->rounds = rounds;
}

// Pass an array of Player objects??
void Game::start(Player * ptrPlayer) {
    std::cout << "Game::start() called" << std::endl;
    std::cout << ptrPlayer->rollDie() << std::endl;
}

// SHOULD be private??
void Game::addPlayer(Player * ptrPlayer) { contestants.push_back(ptrPlayer); }

void Game::end() {

}

void Game::showPlayer() {
    
}