/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Zoo class provides the base structure for the Zoo
** Tycoon game. Each day a random event occurs and the user will have
** to maintain the cost and operation of the Zoo. The game ends when
** the user runs out of money.
*********************************************************************/
/**
 *	REQ: The zoo class should have a dynamic array for each type of 
 *	animal. Each dynamic array should have a capacity of 10 animals 
 *	to start with. If more animals are added, you should resize the 
 *	dynamic array by doubling the starting capacity to hold more 
 *	animals.
 */
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

enum species { TIGER, PENGUIN, TURTLE };
enum randomEvent { NOTHING, SICKNESS, ATTENDANCE_BOOM, BIRTH };

// TODO: Work on the array dynamica resize
class Zoo {
	private:
		int dashLength = 50;	// REMOVE
		int accountBalance;		// Should be declared STATIC
		int days = 0;
		int numberOfBabyTigers = 1;
		// int numberOfBabyPenguins = 5;
		// int numberOfBabyTurtles = 10;
		int numberOfTigers = 0;
		int tigerCapacity = 1;
		// int penguinCapacity = 10;
		// int turtleCapacity = 10;
		Tiger ** ptrTigers = new Tiger*[tigerCapacity]();
		// Penguin ** ptrPenguin = new Penguin*[penguinCapacity]();
		// Turtle ** ptrTurtle = new Turtle*[turtleCapacity]();
		void increaseAnimalAge();
		void feedAnimals();
		void collectProfits();
		void increaseAnimalCapacity(species);	// TODO... why doesnt this work... :[
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
		void babyAnimalBorn(species);	// private??
		int getNumberOfTigers() const;
};
#endif	// ZOO_HPP