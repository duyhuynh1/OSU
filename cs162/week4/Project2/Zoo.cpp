/*********************************************************************
** Program name: Zoo Tycoon
** Author: Tony Huynh
** Date: 04/29/2018
** Description: The Zoo class provides the base structure for the Zoo
** Tycoon game. Each day a random event occurs and the user will have
** to maintain the cost and operation of the Zoo. The game ends when
** the user runs out of money.
*********************************************************************/
#include "Zoo.hpp"

/**
 *	Zoo class default constructor
 */
Zoo::Zoo() {
	std::cout << "Zoo::Zoo default constructor called" << std::endl;
	std::srand(std::time(nullptr));
}

/**
 *	Zoo class destructor. Clean up the arrays
 */
Zoo::~Zoo() {
	std::cout << "\nZoo::~Zoo destructor called" << std::endl;
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			delete ptrTigers[i];
		}	
	}
	delete [] ptrTigers;
}

/**
 *	Initialize the Zoo Tycoon game, by initializing an balance and
 *	prompting the user to purchase animals.
 *	REQ: - The player begins with a specific amount of money in the bank, e.g. 100,000 dollars. 
 *	REQ: - At the start, the user needs to buy three types of animals 
 *	(ptrTigers, ptrPenguin, ptrTurtle) to start the business. 
 *	- Each type should have a quantity of either 1 or 2. 
 *	- For each animal bought, the cost is subtracted from the bank. 
 *	- All newly bought animals are **1 day old**.
 */
void Zoo::init(int &startingBalance) {
	std::cout << "Zoo::init called" << std::endl;
	this->accountBalance = startingBalance;
	purchaseAnimal(TIGER);
	// purchaseAnimal(PENGUIN);
	// purchaseAnimal(TURTLE);
}

/**
 *	Increase the number of days value each time function called.
 *	Also increases the age of all animals in zoo.
 *	REQ: - Each turn is a “day”. 
  - At the beginning of the day, all animals increase age by 1 day, 
    and the user needs to pay the feeding cost of each animal. 
    Feeding is required so the animals don’t die. 
  - After the feeding cost is subtracted from the bank, one 
    randomized event takes place during the day.
  - You can determine how to implement the random functions by yourself. 
 */
void Zoo::running() {
	std::cout << std::string(dashLength,'-') << std::endl;
	std::cout << "Zoo::running() called" << std::endl;
	std::cout << "[D]: previous day = " << days;
	days += 1;
	// Increase the age of all animals
	std::cout << "\t[D]: current day = " << days << std::endl;
	increaseAnimalAge();
	feedAnimals();
	randomEvent();
	collectProfits();
}

/**
 *	Helper function
 */
void Zoo::showZooInfo() {
	std::cout << std::string(dashLength, '-') << std::endl;	// REMOVE
	std::cout << "Account Balance: " << getAccountBalance() << std::endl;
	std::cout << "Number of Tigers = " << numberOfTigers;
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			std::cout << "\nTiger[" << i << "]: {"
					  << " age: " << ptrTigers[i]->getAge() << ","
					  << " cost: " << ptrTigers[i]->getCost() << ","
					  << " numberOfBabies: " << ptrTigers[i]->getNumberOfBabies() << ","
					  << " payoff: " << ptrTigers[i]->getPayoff() << ","
			  		  << " baseFoodCost: " << ptrTigers[i]->getBaseFoodCost()
			  		  << " }" << std::endl;
		}
	}
	// for (int i = 0; i < penguinCapacity; i++) {
	// 	if (ptrPenguin[i] != NULL) {
	// 		std::cout << "\nPenguin {"
	// 				  << "\n  age: " << ptrPenguin[i]->getAge()
	// 				  << "\n  cost: " << ptrPenguin[i]->getCost()
	// 				  << "\n  numberOfBabies: " << ptrPenguin[i]->getNumberOfBabies()
	// 				  << "\n  payoff: " << ptrPenguin[i]->getPayoff()
	// 				  << "\n  baseFoodCost: " << ptrPenguin[i]->getBaseFoodCost()
	// 				  << "\n}";
	// 	}
	// }
	// for (int i = 0; i < turtleCapacity; i++) {
	// 	if (ptrTurtle[i] != NULL) {
	// 		std::cout << "\nTurtle {"
	// 				  << "\n  age: " << ptrTurtle[i]->getAge()
	// 				  << "\n  cost: " << ptrTurtle[i]->getCost()
	// 				  << "\n  numberOfBabies: " << ptrTurtle[i]->getNumberOfBabies()
	// 				  << "\n  payoff: " << ptrTurtle[i]->getPayoff()
	// 				  << "\n  baseFoodCost: " << ptrTurtle[i]->getBaseFoodCost()
	// 				  << "\n}";
	// 	}
	// }
}

/**
 *	Display the current account balance
 */
int Zoo::getAccountBalance() const { return accountBalance; }

/**
 *	Add the newly born/purchased Animal to their appropriate group
 */
void Zoo::addAnimal(Animal * newAnimal, species type) {
	bool maxCapacity = false;
	int index = 0;
	switch (type) {
		case TIGER:
			std::cout << "adding a tiger" << std::endl;	// REMOVE
			while (ptrTigers[index] != nullptr && index < tigerCapacity) {
				index++;
				if (index == tigerCapacity) {
					maxCapacity = true;
				}
			}
			if (maxCapacity) {
				std::cout << "need to increase capacity!" << std::endl;	// REMOVE
				increaseAnimalCapacity(type);
				index = 0;	// Reset to beginning
				while (ptrTigers[index] != nullptr && index < tigerCapacity) {
					index++;
				}
				std::cout << "new vancant spot found at ptrTigers[" << index << "]" << std::endl;	// REMOVE
				ptrTigers[index] = dynamic_cast<Tiger *>(newAnimal);
				numberOfTigers++;
			} else {
				std::cout << "found a vacant spot at ptrTigers[" << index << "]" << std::endl;	// REMOVE
				// numberOfTigers++;
				ptrTigers[index] = dynamic_cast<Tiger *>(newAnimal);
				numberOfTigers++;
			}
			break;
		case PENGUIN:
			// while (ptrPenguin[index] != nullptr && index < penguinCapacity) {
			// 	index++;
			// }
			// std::cout << "adding a penguin" << std::endl;	// REMOVE
			// ptrPenguin[index] = dynamic_cast<Penguin *>(newAnimal);
			break;
		case TURTLE:
			// while (ptrTurtle[index] != nullptr && index < turtleCapacity) {
			// 	index++;
			// }
			// std::cout << "adding a turtle" << std::endl;	// REMOVE
			// ptrTurtle[index] = dynamic_cast<Turtle *>(newAnimal);
			break;
	}
}

/**
 *	Purchase a type of animal and deduct its cost from the account balance.
 */
void Zoo::purchaseAnimal(species type) {
	Animal * animal = nullptr;
	switch (type) {
		case TIGER:
			std::cout << "[D]: purchased a Tiger" << std::endl;	// REMOVE 
			animal = new Tiger(1);
			accountBalance -= animal->getCost();
			addAnimal(animal, type);
			break;
		case PENGUIN:
			// animal = new Penguin(1);
			// accountBalance -= animal->getCost();
			// addAnimal(animal, type);
			break;
		case TURTLE:
			// animal = new Turtle(1);
			// accountBalance -= animal->getCost();
			// addAnimal(animal, type);
			break;
	}
	animal = nullptr;
	delete animal;

}

/**
 *	
 */
void Zoo::babyAnimalBorn(species type) {
	Animal * animal = nullptr;
	switch (type) {
		case TIGER:
			std::cout << "[D]: new baby tiger!" << std::endl;
			animal = new Tiger(0);
			addAnimal(animal, type);
			numberOfBabyTigers--;
			break;
		case PENGUIN:
			std::cout << "[D]: new baby penguin!" << std::endl;
			break;
		case TURTLE:
			std::cout << "[D]: new baby turtle!" << std::endl;
			break;
	}
	animal = nullptr;
	delete animal;
}

/**
 *
 */
int Zoo::getNumberOfTigers() const { return numberOfTigers; }

/**
 *	Increase all the animal's age by +1
 */
void Zoo::increaseAnimalAge() {
	std::cout << "Zoo::increaseAnimalAge called" << std::endl;	// REMOVE
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			ptrTigers[i]->increaseAge();
		}
	}
	// std::cout << numOfptrPenguin << std::endl;
	// for (int i = 0; i < numOfptrPenguin; i++) {
	// 	if (ptrPenguin[i] != nullptr) {
	// 		ptrPenguin[i]->increaseAge();
	// 	}
	// }
	// for (int i = 0; i < numOfptrTurtle; i++) {
	// 	if (ptrTurtle[i] != nullptr) {
	// 		ptrTurtle[i]->increaseAge();
	// 	}
	// }
	// Feed all animals inside the zoo
}

/**
 *	Must feed the animals daily to keep them alive
 */
void Zoo::feedAnimals() {
	std::cout << "Zoo::feedAnimals called" << std::endl;	// REMOVE
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			std::cout << "Tiger[" << i << "] -> - $50" << std::endl;
			accountBalance -= ptrTigers[i]->getBaseFoodCost();
		}
	}
}

/**
 *	Total all animal payoffs and add to accountBalance
 */
void Zoo::collectProfits() {
	std::cout << "Zoo::collectProfits called" << std::endl;	// REMOVE
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			std::cout << "Tiger[" << i << "] -> + $2000" << std::endl;	// REMOVE
			accountBalance += ptrTigers[i]->getPayoff();
		}
	}
}

/**
 *	Double the capacity for the specified species. Handles
 *	issue with adding new born/purchased animals when there
 *	is no more room to store them.
 */
void Zoo::increaseAnimalCapacity(species type) {
	int oldCapacity = 0;
	Tiger ** tempTiger = nullptr;
	// Penguin ** tempPenguin = nullptr;
	// Turtle ** tempTurtle = nullptr;
	std::cout << "Zoo::increaseAnimalCapacity called" << std::endl;
	switch (type) {
		case TIGER:
			oldCapacity = tigerCapacity;
			tigerCapacity *= 2;
			tempTiger = new Tiger*[tigerCapacity]();
			for (int i = 0; i < oldCapacity; i++) {
				tempTiger[i] = ptrTigers[i];
			}
			delete [] ptrTigers;
			ptrTigers = tempTiger;
			std::cout << "increase success!!" << std::endl;
			break;
		case PENGUIN:
			break;
		case TURTLE:
			break;
	}
}

/**
 *	
 */
void Zoo::randomEvent() {
	// int event = (rand() % 4);
	int event = 1;	// REMOVE
	int bonus = 0;
	int randomDeath = rand() % 3;
	std::cout << "[D]: event = " << event << std::endl;
	switch (event) {
		case NOTHING:
			std::cout << "[D]: Random Event: NOTHING..." << std::endl;	// REMOVE
			break;
		case SICKNESS:
			std::cout << "[D]: Random Event: SICKNESS..." << std::endl;	// REMOVE			
			if (randomDeath == 0) {
				int index = rand() % getNumberOfTigers();
				std::cout << "Tiger[" << index << "] has died..." << std::endl;
				ptrTigers[index] = nullptr;
				numberOfTigers--;
				std::cout << "a tiger dies..." << std::endl;
			} else if (randomDeath == 1) {
				std::cout << "a penguin dies..." << std::endl;
				// numberOfPenguins--;
			} else if (randomDeath == 2) {
				std::cout << "a turtle dies..." << std::endl;
				// numberOfTurtles--;
			}
			break;
		case ATTENDANCE_BOOM:
			std::cout << "[D]: Random Event: ATTENDANCE_BOOM...Bonus = ${250 - 500}" << std::endl;	// REMOVE
			bonus = (rand() % 251) + 250;
			std::cout << "BONUS[!] -> " << bonus;	// REMOVE
			bonus *= numberOfTigers;
			std::cout << " * " << numberOfTigers << " Tigers = $" 
					  << bonus << std::endl;	// REMOVE
			accountBalance += bonus;
			break;
		case BIRTH:
			std::cout << "[D]: Random Event: BIRTH..." << std::endl;
			bool foundAdultTiger = false;
			int selection;
			std::vector<int> groupWithAdult;
			for (int i = 0; i < getNumberOfTigers(); i++) {
				if (ptrTigers[i]->isAdult()) {
					foundAdultTiger = true;
					std::cout << "[D]: found an adult in the tiger group" << std::endl; // REMOVE
					break;
				}
			}
			std::cout << "numberOfBabyTigers = " << numberOfBabyTigers << std::endl;	// REMOVE
			if (foundAdultTiger && numberOfBabyTigers > 0) {
				groupWithAdult.push_back(0);	// TIGER = index 0
			}
			// for (int i = 0; i < numberOfPenguins; i++) {
			// 	if (ptrPenguin[i]->isAdult()) {
			// 		std::cout << "[D]:  found an adult in the penguin group" << std::endl;
			// 	}
			// }
			if (!groupWithAdult.empty()) {
				std::cout << "[D]: selected a group" << std::endl;
				selection = rand() % groupWithAdult.size();
			} else {
				selection = -1;
			}
			std::cout << "selection = " << selection << std::endl;
			switch (selection) {
				case TIGER:
					babyAnimalBorn(TIGER);
					break;
				case PENGUIN:
					babyAnimalBorn(PENGUIN);
					break;
				case TURTLE:
					babyAnimalBorn(TURTLE);
					break;
				case -1:
					std::cout << "None of the animals are adults..." << std::endl;
					break;
			}
			break;
	}
}