// The player has the two prompts, one to move and another to inspect the Space.

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Space.hpp"
#include "Menu.hpp"
#include "Option.hpp"

class Player {
    private:
        Menu menu;
        bool exit = false;
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
        bool foundExit();
};
#endif  // PLAYER_HPP_