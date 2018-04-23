#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include <vector>

class Game {
    private:
        int rounds;
        int playerScore[2];
        std::vector<Player *> contestants;
    public:
        Game(int rounds);
        void start(Player * ptrPlayer);
        void addPlayer(Player * ptrPlayer);
        void end();
        void showPlayer() const;
};
#endif  // GAME_HPP