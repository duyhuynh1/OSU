#include <iostream>
#include "Die.hpp"  // REMOVE
#include "LoadedDie.hpp"    // REMOVE
#include "Player.hpp"   // REMOVE
#include "Menu.hpp"

enum DieType { NORMAL = 1, LOADED = 2 };

int main() {
    mainMenu();
    // int side = 6;
    // Die * ptrDie1 = NULL;
    // // Die * ptrDie2 = NULL;
    // ptrDie1 = new LoadedDie(side);
    // // ptrDie2 = new LoadedDie(side);
    // Player * ptrPlayer1 = new Player("player1", ptrDie1);
    // // Player * ptrPlayer2 = new Player("player2", ptrDie2);
    // std::cout << "Player 1 rolls dice " << ptrPlayer1->rollDie() << std::endl;
    // // std::cout << "Player 2 rolls dice " << ptrPlayer2->rollDie() << std::endl;

    // // Clean up
    // delete ptrPlayer1;
    // delete ptrDie1;
    // delete [] ptrDie2;
    
    // delete [] ptrPlayer2;

    // DieType p1Die;
    // DieType p2Die;

    // std::cout << "Die1 Type = ";
    // std::cin >> p1Die;
    // std::cout << "Die2 Type = ";
    // std::cin >> p2Die;

    // switch (p1Die) {
    //     case NORMAL:
    //         std::cout << "p1 selected a NORMAL die" << std::endl;
    //         die1 = new Die(6);
    //         break;
    //     case LOADED:
    //         std::cout << "p1 selected a LOADED die" << std::endl;
    //         die1 = new Die(6);
    //         break;
    // }

    // Player p1("player1", &die1);
    // // Player p2("player2", &die2);

    // std::cout << p1.rollDie() << std::endl;
    // std::cout << p2.rollDie() << std::endl;

    // mainMenu();

    return 0;
}