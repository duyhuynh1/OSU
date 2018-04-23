#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>     // REMOVE
#include "Die.hpp"

class Player {
    private:
        std::string name = "";
        Die * ptrDie = NULL;
    public:
        Player(std::string name, Die * ptrDie);
        ~Player();
        std::string getName() const;
        int rollDie();
};
#endif  // PLAYER_HPP