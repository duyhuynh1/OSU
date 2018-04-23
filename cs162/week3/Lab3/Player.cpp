#include "Player.hpp"

Player::Player(std::string name, Die * ptrDie) {
    std::cout << "Player constructor called" << std::endl;  // REMOVE
    std::cout << ptrDie << std::endl;   // REMOVE
    this->name = name;
    this->ptrDie = ptrDie;
}

Player::~Player() {
    std::cout << "~Player() destructor called" << std::endl;    // REMOVE
}

/**
 *  Return's the player's name
 */
std::string Player::getName() const {
    return name;
}

/**
 *  Return's the Player's dice roll value
 */
int Player::rollDie() {
    return ptrDie->roll();
}