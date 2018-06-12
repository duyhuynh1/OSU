/*********************************************************************
** Program name: Labyrinth Escape
** Author: Tony Huynh
** Date: 6/12/2018
** Description: Driver program for the Labyrinth Escape game.
** Initializes the static map with a variety of types of Space.
*********************************************************************/
#include <iostream>
#include "Space.hpp"
#include "ItemSpace.hpp"
#include "PressurePlateSpace.hpp"
#include "LockedItemSpace.hpp"
#include "LockedDoorSpace.hpp"
#include "Player.hpp"
#include "Menu.hpp"
#include "Option.hpp"

void introduction();

int main() {
    introduction();
    // Map initialization
    // [2]-[▃]
    //  |
    // [1]-[□] [▣]
    //      ?   |
    // [5]-[3]?[6]-[╏]<---Exit
    //  |   |   |
    // [▃] [4] [□]
    //      |
    //     [□]
    std::string pathNotify = "[EVENT]: A new path has been made!\n";
    std::string mainPrompt = "1. Play game\n2. Quit\n=>";
    std::string difficultyPrompt = "1. Easy\n2. Normal\n3. Hard\n=>";
    std::string replayPrompt = "1. Play again\n2. Quit\n=>";

    Option option1(mainPrompt, 1, 2);
    Option option2(difficultyPrompt, 1, 3);
    Option option3(replayPrompt, 1, 2);

    Menu mainMenu;
    mainMenu.addOption(option1);
    mainMenu.addOption(option2);
    mainMenu.addOption(option3);

    Space space1, space2, space3, space4, space5, space6;
    PressurePlateSpace switch1, switch2;
    ItemSpace item1("rock");
    ItemSpace item2("rock");
    ItemSpace item3("key");
    LockedItemSpace lockedItem1("door key");
    LockedDoorSpace door1;

    // Section 1 created
    space1.topConnectToBottomOf(space2);
    space1.rightConnectToLeftOf(item1);
    space2.bottomConnectToTopOf(space1);
    space2.rightConnectToLeftOf(switch1);
    item1.leftConnectToRightOf(space1);
    switch1.leftConnectToRightOf(space2);
    // Section 2 created
    space3.leftConnectToRightOf(space5);
    space3.bottomConnectToTopOf(space4);
    space4.topConnectToBottomOf(space3);
    space4.bottomConnectToTopOf(item2);
    space5.rightConnectToLeftOf(space3);
    space5.bottomConnectToTopOf(switch2);
    item2.topConnectToBottomOf(space4);
    switch2.topConnectToBottomOf(space5);
    // Section 3 created
    space6.topConnectToBottomOf(lockedItem1);
    space6.rightConnectToLeftOf(door1);
    space6.bottomConnectToTopOf(item3);
    door1.leftConnectToRightOf(space6);
    item3.topConnectToBottomOf(space6);
    lockedItem1.bottomConnectToTopOf(space6);

    Player p1(space1);

    int turn = 0;
    int maxTurn = 0;

    bool exit = false;
    do {
        std::cout << "\n";
        std::cout << std::string(75, '-') << std::endl;
        std::cout << "[Main menu]:\n";
        std::cout << std::string(75, '-') << std::endl;
        switch (mainMenu.getUnsignedInteger(0)) {
            case 1:
                std::cout << std::string(75, '-') << std::endl;
                std::cout << "[Difficulty Selection]:\n";
                std::cout << std::string(75, '-') << std::endl;
                switch (mainMenu.getUnsignedInteger(1)) {
                    case 1:
                        turn = maxTurn = 50;
                        break;
                    case 2:
                        turn = maxTurn = 35;
                        break;
                    case 3:
                        turn = maxTurn = 23;  // Minimum amount of steps required
                        break;
                }
                while (turn > 0) {
                    if (p1.foundExit()) {   // Check game status
                        turn = 0;
                        std::cout << std::string(75, '=') << std::endl;
                        std::cout << "Congrats you've escape unharmed!\n";
                        std::cout << std::string(75, '=') << std::endl;
                    } else {
                        std::cout << "[Turns remaining]: " << turn << "\n";
                        if (turn == (maxTurn / 2)) {
                            std::cout << "[W]: The lights are starting to dim...\n";
                        } else if (turn == (maxTurn / 3)) {
                            std::cout << "[W]: The lights is slowly fading...\n";
                        } else if (turn == (maxTurn / 4)) {
                            std::cout << "[W]: Almost out of time! Hurry!\n";
                        }
                        p1.showInventory();
                        p1.showPosition();
                        p1.move();
                        p1.inspectSpace();
                        // Establish 1st connection
                        if (switch1.isActivated() && item1.bottom == nullptr) {
                            std::cout << pathNotify;
                            item1.bottomConnectToTopOf(space3);
                            space3.topConnectToBottomOf(item1);
                        }
                        // Establish 2nd connection
                        if (switch2.isActivated() && space3.right == nullptr) {
                            std::cout << pathNotify;
                            space3.rightConnectToLeftOf(space6);
                            space6.leftConnectToRightOf(space3);
                        }
                        turn--;
                    }
                }
                std::cout << std::string(75, '-') << std::endl;
                if (!p1.foundExit()) { std::cout << "GAME OVER\n"; }
                std::cout << std::string(75, '-') << std::endl;
                if (mainMenu.getUnsignedInteger(2) == 2) {
                    std::cout << ">>> Exit Game <<<\n";
                    exit = true;
                }
                break;
            case 2:
                std::cout << ">>> Exit Game <<<\n";
                exit = true;
                break;
        }
    } while (!exit);

    return 0;
}

void introduction() {
    std::cout << std::string(75, '=') << std::endl;
    std::cout << "> Labyrinth Escape <\n";
    std::cout << std::string(75, '=') << std::endl;
    std::cout << "[Objective]:\n";
    std::cout << "  You are currently trapped inside a mysterious labyrinth.\n"
                 "  Torches illuminate your surroundings, but not for long.\n"
                 "  Explore the maze and find your way out. Before it is too late.\n"
                 "  [Hint]: Seek locked door [╏] and it will lead you out. Good luck!\n";
    std::cout << "\n[Legend]:\n";
    std::cout << "  [*] - This is you. Don't forget this one, it's kind of important.\n";
    std::cout << "  [ ] - Empty space. Nothing really here.\n";
    std::cout << "  [▣] - Locked item chest. Requires a key to open.\n";
    std::cout << "  [□] - Unsecured item chest. Drops an item.\n";
    std::cout << "  [▃] - Pressure switch. Requires heavy object to activate.\n";
    std::cout << "  [╏] - Locked Door. Requires a door key to open.\n";
    std::cout << std::string(75, '-') << std::endl;
}