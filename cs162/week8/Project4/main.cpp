/*********************************************************************
** Program name: Fantasy Combat Tournament
** Author: Tony Huynh
** Date: 5/27/1618
** Description: Driver program that allows user to test different
** types of characters in combat.
*********************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Option.hpp"
#include "Tournament.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

int main() {
    std::string mainMenuPrompt = "1) Play\n2) Exit\n=> ";
    std::string numOfPlayersPrompt = "Enter the number of fighters per team (min: 1, max: 10): ";
    std::string playerSelectionPrompt = "1) Vampire\n2) Barbarian\n3) Blue Men\n"
                                        "4) Medusa\n5) Harry Potter\n=> ";
    std::string playerNamePrompt = "Enter a name for the fighter: ";
    std::string replayMenuPrompt = "1) Play Again\n2) Exit\n=> ";

    Queue *teamA = new Queue();
    Queue *teamB = new Queue();
    Queue *loserPile = new Queue();
    Tournament mTournament;

    Option *option1 = new Option(mainMenuPrompt, 1, 2);
    Option *option2 = new Option(numOfPlayersPrompt, 1, 10);    // Limit to 10 per side
    Option *option3 = new Option(playerSelectionPrompt, 1, 5);
    Option *option4 = new Option(playerSelectionPrompt, 1, 5);
    Option *option5 = new Option(playerNamePrompt);
    Option *option6 = new Option(replayMenuPrompt, 1, 2);

    Menu mMenu;
    mMenu.addOption(option1);   // Index 0
    mMenu.addOption(option2);   // Index 1
    mMenu.addOption(option3);   // Index 2
    mMenu.addOption(option4);   // Index 3
    mMenu.addOption(option5);   // Index 4
    mMenu.addOption(option6);   // Index 5

    int playerOneSeletion = 0;
    int playerTwoSelection = 0;
    std::string playerOneSelectionName = "";
    std::string playerTwoSelectionName = "";

    int numOfPlayersPerTeam = 0;

    std::cout << std::string(50, '=') << std::endl;
    std::cout << "Fantasy Combat Tournament\n";
    std::cout << std::string(50, '=') << std::endl;
    int selection = mMenu.getUnsignedInteger(0);
    bool done = false;
    do {
        switch (selection) {
            case 1:
                numOfPlayersPerTeam = mMenu.getUnsignedInteger(1);
                for (int i = 0; i < numOfPlayersPerTeam; i++) {
                    std::cout << std::string(50, '-') << std::endl;
                    std::cout << "Team A Character Selection\n";
                    std::cout << std::string(50, '-') << std::endl;
                    playerOneSeletion = mMenu.getUnsignedInteger(2);
                    switch (playerOneSeletion) {
                        case 1:
                            teamA->addBack(new Vampire(mMenu.getString(4)));
                            break;
                        case 2:
                            teamA->addBack(new Barbarian(mMenu.getString(4)));
                            break;
                        case 3:
                            teamA->addBack(new BlueMen(mMenu.getString(4)));
                            break;
                        case 4:
                            teamA->addBack(new Medusa(mMenu.getString(4)));
                            break;
                        case 5:
                            teamA->addBack(new HarryPotter(mMenu.getString(4)));
                            break;
                    }
                    std::cout << std::string(50, '-') << std::endl;
                    std::cout << "Team B Character Selection\n";
                    std::cout << std::string(50, '-') << std::endl;
                    playerTwoSelection = mMenu.getUnsignedInteger(2);
                    switch (playerTwoSelection) {
                        case 1:
                            teamB->addBack(new Vampire(mMenu.getString(4)));
                            break;
                        case 2:
                            teamB->addBack(new Barbarian(mMenu.getString(4)));
                            break;
                        case 3:
                            teamB->addBack(new BlueMen(mMenu.getString(4)));
                            break;                        
                        case 4:
                            teamB->addBack(new Medusa(mMenu.getString(4)));
                            break;;
                        case 5:
                            teamB->addBack(new HarryPotter(mMenu.getString(4)));
                            break;
                    }
                }
                // Character selection complete
                std::cout << std::string(50, '-') << std::endl;
                std::cout << "Starting Player Lineup\n";
                std::cout << std::string(50, '-') << std::endl;
                mTournament.init(teamA, teamB, loserPile);
                mTournament.getQueueInfo();
                mTournament.start();
                selection = mMenu.getUnsignedInteger(5);
                if (selection == 2) { 
                    done = true;
                    std::cout << ">>> EXIT GAME <<<" << std::endl;
                }
                delete teamA;
                delete teamB;
                delete loserPile;
                teamA = new Queue();
                teamB = new Queue();
                loserPile = new Queue();
                break;
            case 2:
                done = true;
                std::cout << ">>> EXIT GAME <<<" << std::endl;
                break;
        }
    } while(!done);

    delete option1;
    delete option2;
    delete option3;
    delete option4;
    delete option5;
    delete option6;
	return 0;
}