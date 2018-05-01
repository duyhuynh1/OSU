/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Zoo class provides the base structure for the Zoo
** Tycoon game. Each day a random event occurs and the user will have
** to maintain the cost and operation of the Zoo. The game ends when
** the user runs out of money.
*********************************************************************/
#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <stdlib.h>		// srand, rand
#include <time.h>		// time
#include <vector>
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

enum gameState { PLAYING, END };
enum species { TIGER, PENGUIN, TURTLE };
enum randomEvent { NOTHING, SICKNESS, ATTENDANCE_BOOM, BIRTH };

class Zoo {
	private:
		gameState state;
		int dashLength = 100;
		int accountBalance;
		int days = 0;
		int numberOfBabyTigers = 1;
		int numberOfBabyPenguins = 5;
		int numberOfBabyTurtles = 10;
		int numberOfTigers = 0;
		int numberOfPenguins = 0;
		int numberOfTurtles = 0;
		int tigerCapacity = 10;
		int penguinCapacity = 10;
		int turtleCapacity = 10;
		Tiger ** ptrTigers = new Tiger*[tigerCapacity]();
		Penguin ** ptrPenguin = new Penguin*[penguinCapacity]();
		Turtle ** ptrTurtle = new Turtle*[turtleCapacity]();
		void increaseAnimalAge();
		void feedAnimals();
		void collectProfits();
		void increaseAnimalCapacity(species);
		void randomEvent();
	public:
		Zoo();
		~Zoo();
		void init(int &);
		void running();
		void showZooInfo();
		int getAccountBalance() const;
		void addAnimal(Animal *, species);
		void purchaseAnimal(species);
		void babyAnimalBorn(species);
		int getNumberOfTigers() const;
		int getNumberOfPenguins() const;
		int getNumberOfTurtles() const;
		std::string getGameState() const;
		void setGameState(gameState);
};
#endif	// ZOO_HPP