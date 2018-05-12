/*********************************************************************
** Program name: Fantasy Combat Game
** Author: Tony Huynh
** Date: 5/13/2018
** Description: Driver program that allows user to test different
** types of characters in combat.
*********************************************************************/
#include <iostream>
#include "Game.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

// There are 15 possible fighting scenarios
// Game mGame;
// mGame.init(p1, p2);
// mGame.start();
// mGame.end();

int main() {
    // Character *p1 = new Barbarian();
    // Character *p2 = new Barbarian();

    // Character *p3 = new Vampire();
    // Character *p4 = new Vampire();

    Character *p5 = new Medusa();
    // Character *p6 = new Medusa();

    // Character *p7 = new BlueMen();
    // Character *p8 = new BlueMen();

    Character *p9 = new HarryPotter();
    // Character *p10 = new HarryPotter();

    Game mGame;
    // mGame.init(p1, p2);
    // mGame.start();
    // mGame.getInfo();
    std::cout << std::string(50, '-') << std::endl;
    mGame.init(p5, p9);
    mGame.start();

    // delete p1;
    // delete p2;
    // delete p3;
    // delete p4;
    // delete p3;
    delete p5;
    // delete p6;
    // delete p7;
    // delete p8;
    delete p9;
    // delete p10;
	return 0;
}