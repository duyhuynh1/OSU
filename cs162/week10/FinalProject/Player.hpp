// The player has the two prompts, one to move and another to inspect the Space.

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Space.hpp"

class Player {
    private:
        int xPos = 0;
        int yPos = 0;
        std::string inventory[1] = {" "};
        Space* current = nullptr;
        void showSpace(Space*);
    public:
        Player(Space&);
        void move();
        void inspectSpace();
        void store(std::string);
        void showInventory();
        void showPosition();
};
#endif  // PLAYER_HPP_