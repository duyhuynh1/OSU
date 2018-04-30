/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Zoo Tycoon game's driver program.
*********************************************************************/
#include <iostream>
#include "Zoo.hpp"
#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"
#include <typeinfo>

int main() {
	int startAmount = 100000;
	Zoo mZoo;
	mZoo.init(startAmount);

	mZoo.running();
	mZoo.purchaseAnimal(TIGER);
	mZoo.showZooInfo();

	// mZoo.running();
	// mZoo.showZooInfo();

	// mZoo.running();
	// mZoo.showZooInfo();
	// std::cout << "\nTiger {"
	// 		  << "\n  age: " << ptrAnimal1->getAge()
	// 		  << "\n  cost: " << ptrAnimal1->getCost()
	// 		  << "\n  numberOfBabies: " << ptrAnimal1->getNumberOfBabies()
	// 		  << "\n  payoff: " << ptrAnimal1->getPayoff()
	// 		  << "\n  baseFoodCost: " << ptrAnimal1->getBaseFoodCost()
	// 		  << "\n}";
	// std::cout << "\nPenguin {"
	// 		  << "\n  age: " << ptrAnimal2->getAge()
	// 		  << "\n  cost: " << ptrAnimal2->getCost()
	// 		  << "\n  numberOfBabies: " << ptrAnimal2->getNumberOfBabies()
	// 		  << "\n  payoff: " << ptrAnimal2->getPayoff()
	// 		  << "\n  baseFoodCost: " << ptrAnimal2->getBaseFoodCost()
	// 		  << "\n}";
	// std::cout << "\nTurtle {"
	// 		  << "\n  age: " << ptrAnimal3->getAge()
	// 		  << "\n  cost: " << ptrAnimal3->getCost()
	// 		  << "\n  numberOfBabies: " << ptrAnimal3->getNumberOfBabies()
	// 		  << "\n  payoff: " << ptrAnimal3->getPayoff()
	// 		  << "\n  baseFoodCost: " << ptrAnimal3->getBaseFoodCost()
	// 		  << "\n}";
	return 0;
}