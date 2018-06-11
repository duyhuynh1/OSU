// The player has the two prompts, one to move and another to inspect the Space.

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Space.hpp"

class Player {
    private:
        std::string inventory[1] = {" "};
        Space* current = nullptr;
    public:
        Player(Space&);
        void move();
        void inspectSpace();
        void store(std::string);
        void showInventory();
};
#endif  // PLAYER_HPP_