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
	std::srand(time(nullptr));
}

/**
 *	Zoo class destructor. Clean up the arrays
 */
Zoo::~Zoo() {
	for (int i = 0; i < numberOfTigers; i++) {
		if (ptrTigers[i] != nullptr) {
			delete ptrTigers[i];
		}
	}
	delete [] ptrTigers;
	for (int i = 0; i < numberOfPenguins; i++) {
		if (ptrPenguin[i] != nullptr) {
			delete ptrPenguin[i];
		}
	}
	delete [] ptrPenguin;
	for (int i = 0; i < numberOfTurtles; i++) {
		if (ptrTurtle[i] != nullptr) {
			delete ptrTurtle[i];
		}
	}
	delete [] ptrTurtle;
}

/**
 *	Initialize the Zoo Tycoon game, by initializing an balance and
 *	prompting the user to purchase animals.
 */
void Zoo::init(int &startingBalance) {
	this->accountBalance = startingBalance;
	std::cout << std::string(dashLength, '-') << std::endl;
	std::cout << "[DAY#]: " << days << " | "
		      << "[ACCOUNT BALANCE]: $" << accountBalance << " | "
		      << "[GAME LOADED]" << std::endl;
	std::cout << std::string(dashLength, '-') << std::endl;
	ptrTigers[0] = new Tiger(1);
	numberOfTigers++;
	accountBalance -= ptrTigers[0]->getCost();
	ptrPenguin[0] = new Penguin(1);
	numberOfPenguins++;
	accountBalance -= ptrPenguin[0]->getCost();
	ptrTurtle[0] = new Turtle(1);
	numberOfTurtles++;
	accountBalance -= ptrTurtle[0]->getCost();
	state = PLAYING;
	showZooInfo();
	running();
}

/**
 *	Increase the number of days value each time function called.
 *	Also increases the age of all animals in zoo.
 *	Perform feeding process and collect payoff at end of day
 */
void Zoo::running() {
	if (accountBalance <= 0) {
		state = END;
		std::cout << "[ BANKRUPTED!!! ]" << std::endl;
		std::cout << ">>> Game Over <<<" << std::endl;
	} else {
		std::cout << std::string(dashLength,'-') << std::endl;
		days += 1;
		std::cout << "[DAY#]: " << days << " | "
				  << "[ACCOUNT BALANCE]: $" << accountBalance << " | ";
		increaseAnimalAge();
		feedAnimals();
		randomEvent();
		collectProfits();

	}
}

/**
 *	Helper function
 */
void Zoo::showZooInfo() {
	// std::cout << std::string(dashLength, '-') << std::endl;
	// std::cout << "Account Balance: " << getAccountBalance() << std::endl;
	// std::cout << std::string(dashLength, '-') << std::endl;
	std::cout << "[Number of Tigers]: " << numberOfTigers << std::endl;
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			std::cout << " + Tiger[" << i << "]:";
			ptrTigers[i]->showInfo();
		}
	}
	std::cout << "[Number of Penguins]: " << numberOfPenguins << std::endl;
	for (int i = 0; i < penguinCapacity; i++) {
		if (ptrPenguin[i] != nullptr) {
			std::cout << " + Penguin[" << i << "]:";
			ptrPenguin[i]->showInfo();
		}
	}
	std::cout << "[Number of Turtles]: " << numberOfTurtles << std::endl;
	for (int i = 0; i < turtleCapacity; i++) {
		if (ptrTurtle[i] != nullptr) {
			std::cout << " + Turtle[" << i << "]:";
			ptrTurtle[i]->showInfo();
		}
	}
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
			while (ptrTigers[index] != nullptr && index < tigerCapacity) {
				index++;
				if (index == tigerCapacity) {
					maxCapacity = true;
				}
			}
			if (maxCapacity) {

				increaseAnimalCapacity(type);
				index = 0;	// Reset to beginning
				while (ptrTigers[index] != nullptr && index < tigerCapacity) {
					index++;
				}

				ptrTigers[index] = dynamic_cast<Tiger *>(newAnimal);
				numberOfTigers++;
			} else {

				ptrTigers[index] = dynamic_cast<Tiger *>(newAnimal);
				numberOfTigers++;
			}
			break;
		case PENGUIN:
			while (ptrPenguin[index] != nullptr && index < penguinCapacity) {
				index++;
				if (index == penguinCapacity) {
					maxCapacity = true;
				}
			}
			if (maxCapacity) {

				increaseAnimalCapacity(type);
				index = 0;
				while (ptrPenguin[index] != nullptr && index < penguinCapacity) {
					index++;
				}

				ptrPenguin[index] = dynamic_cast<Penguin *>(newAnimal);
				numberOfPenguins++;
			} else {

				ptrPenguin[index] = dynamic_cast<Penguin *>(newAnimal);
				numberOfPenguins++;
			}
			break;
		case TURTLE:
			while (ptrTurtle[index] != nullptr && index < turtleCapacity) {
				index++;
				if (index == turtleCapacity) {
					maxCapacity = true;
				}
			}
			if (maxCapacity) {

				increaseAnimalCapacity(type);
				index = 0;
				while (ptrTurtle[index] != nullptr && index < turtleCapacity) {
					index++;
				}

				ptrTurtle[index] = dynamic_cast<Turtle *>(newAnimal);
				numberOfTurtles++;
			} else {

				ptrTurtle[index] = dynamic_cast<Turtle *>(newAnimal);
				numberOfTurtles++;
			}
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
			animal = new Tiger(3);
			accountBalance -= animal->getCost();
			addAnimal(animal, type);
			break;
		case PENGUIN:
			animal = new Penguin(3);
			accountBalance -= animal->getCost();
			addAnimal(animal, type);
			break;
		case TURTLE:
			animal = new Turtle(3);
			accountBalance -= animal->getCost();
			addAnimal(animal, type);
			break;
	}
	animal = nullptr;
	delete animal;
}

/**
 *	Add a new baby animal to the appropriate group
 */
void Zoo::babyAnimalBorn(species type) {
	Animal * animal = nullptr;
	switch (type) {
		case TIGER:
			std::cout << "[NEW BABY]: Tiger!" << std::endl;
			animal = new Tiger(0);
			addAnimal(animal, type);
			numberOfBabyTigers--;
			break;
		case PENGUIN:
			std::cout << "[NEW BABY]: Penguin!" << std::endl;
			animal = new Penguin(0);
			addAnimal(animal, type);
			numberOfBabyPenguins--;
			break;
		case TURTLE:
			std::cout << "[NEW BABY]: Turtle!" << std::endl;
			animal = new Turtle(0);
			addAnimal(animal, type);
			numberOfBabyTurtles--;
			break;
	}
	animal = nullptr;
	delete animal;
}

/**
 *	Returns the nubmer of Tigers
 */
int Zoo::getNumberOfTigers() const { return numberOfTigers; }

/**
 *	Returns the number of Penguins
 */
int Zoo::getNumberOfPenguins() const { return numberOfPenguins; }

/**
 *	Returns the number of Turtles
 */
int Zoo::getNumberOfTurtles() const { return numberOfTurtles; }

/**
 *	Increase all the animal's age by +1
 */
void Zoo::increaseAnimalAge() {
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			ptrTigers[i]->increaseAge();
		}
	}
	for (int i = 0; i < penguinCapacity; i++) {
		if (ptrPenguin[i] != nullptr) {
			ptrPenguin[i]->increaseAge();
		}
	}
	for (int i = 0; i < turtleCapacity; i++) {
		if (ptrTurtle[i] != nullptr) {
			ptrTurtle[i]->increaseAge();
		}
	}
}

/**
 *	Must feed the animals daily to keep them alive
 */
void Zoo::feedAnimals() {
	int feedTotal = 0;
	std::cout << "[FEEDING ANIMALS]: ";
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			accountBalance -= ptrTigers[i]->getBaseFoodCost();
			feedTotal += ptrTigers[i]->getBaseFoodCost();
		}
	}
	for (int i = 0; i < penguinCapacity; i++) {
		if (ptrPenguin[i] != nullptr) {
			accountBalance -= ptrPenguin[i]->getBaseFoodCost();
			feedTotal += ptrPenguin[i]->getBaseFoodCost();
		}
	}
	for (int i = 0; i < turtleCapacity; i++) {
		if (ptrTurtle[i] != nullptr) {
			accountBalance -= ptrTurtle[i]->getBaseFoodCost();
			feedTotal += ptrTurtle[i]->getBaseFoodCost();
		}
	}
	std::cout << "- $(" << feedTotal << ")" << " | ";
}

/**
 *	Total all animal payoffs and add to accountBalance
 */
void Zoo::collectProfits() {
	int oldBalance = accountBalance;
	std::cout << "[DAY END]: Total profit $";
	for (int i = 0; i < tigerCapacity; i++) {
		if (ptrTigers[i] != nullptr) {
			accountBalance += ptrTigers[i]->getPayoff();
		}
	}
	for (int i = 0; i < penguinCapacity; i++) {
		if (ptrPenguin[i] != nullptr) {
			accountBalance += ptrPenguin[i]->getPayoff();
		}
	}
	for (int i = 0; i < turtleCapacity; i++) {
		if (ptrTurtle[i] != nullptr) {
			accountBalance += ptrTurtle[i]->getPayoff();
		}
	}
	std::cout << (accountBalance - oldBalance) << std::endl;
}

/**
 *	Double the capacity for the specified species. Handles
 *	issue with adding new born/purchased animals when there
 *	is no more room to store them.
 */
void Zoo::increaseAnimalCapacity(species type) {
	int oldCapacity = 0;
	Tiger ** tempTiger = nullptr;
	Penguin ** tempPenguin = nullptr;
	Turtle ** tempTurtle = nullptr;
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
			break;
		case PENGUIN:
			oldCapacity = penguinCapacity;
			penguinCapacity *= 2;
			tempPenguin = new Penguin*[penguinCapacity]();
			for (int i = 0; i < oldCapacity; i++) {
				tempPenguin[i] = ptrPenguin[i];
			}
			delete [] ptrPenguin;
			ptrPenguin = tempPenguin;
			break;
		case TURTLE:
			oldCapacity = turtleCapacity;
			turtleCapacity *= 2;
			tempTurtle = new Turtle*[turtleCapacity]();
			for (int i = 0; i < oldCapacity; i++) {
				tempTurtle[i] = ptrTurtle[i];
			}
			delete [] ptrTurtle;
			ptrTurtle = tempTurtle;
			break;
	}
}

/**
 *	Invoke the random events stated in the requirements
 */
void Zoo::randomEvent() {
	int event = (rand() % 4);
	int bonus = 0;
	int randomDeath = rand() % 3;
	switch (event) {
		case NOTHING:
			std::cout << "[EVENT]: NOTHING HAPPENED" << std::endl;
			break;
		case SICKNESS:
			std::cout << "[EVENT]: SICKNESS" << std::endl;
			if (randomDeath == 0 && getNumberOfTigers() != 0) {
				int index = rand() % getNumberOfTigers();
				std::cout << "- Tiger[" << index << "] has died..." << std::endl;
				delete ptrTigers[index];
				ptrTigers[index] = nullptr;
				numberOfTigers--;
			} else if (randomDeath == 1 && getNumberOfPenguins() != 0) {
				int index = rand() % getNumberOfPenguins();
				std::cout << "- Penguin[" << index << "] has died..." << std::endl;
				delete ptrPenguin[index];
				ptrPenguin[index] = nullptr;
				numberOfPenguins--;
			} else if (randomDeath == 2 && getNumberOfTurtles() != 0) {
				int index = rand() % getNumberOfTurtles();
				std::cout << "- Turtle[" << index << "] has died..." << std::endl;
				delete ptrTurtle[index];
				ptrTurtle[index] = nullptr;
				numberOfTurtles--;
			}
			break;
		case ATTENDANCE_BOOM:
			std::cout << "[EVENT]: ATTENDANCE BOOM" << std::endl;
			bonus = (rand() % 251) + 250;
			bonus *= numberOfTigers;
			std::cout << "[BONUS]: + $" << bonus << std::endl;
			accountBalance += bonus;
			break;
		case BIRTH:
			std::cout << "[EVENT]: BIRTH" << std::endl;
			bool foundAdultTiger = false;
			bool foundAdultPenguin = false;
			bool foundAdultTurtle = false;

			int selection;
			std::vector<int> groupWithAdult;
			// Find Adult Tiger
			for (int i = 0; i < getNumberOfTigers(); i++) {
				if (ptrTigers[i] != nullptr) {
					if (ptrTigers[i]->isAdult() && ptrTigers[i]->canGiveBirth()) {
						foundAdultTiger = true;
						break;
					}
				}
			}
			// Find Adult penguin
			for (int i = 0; i < getNumberOfPenguins(); i++) {
				if (ptrPenguin[i] != nullptr) {
					if (ptrPenguin[i]->isAdult() && ptrPenguin[i]->canGiveBirth()) {
		
						foundAdultPenguin = true;
						break;
					}
				}
			}
			// Find Adult Turtle
			for (int i = 0; i < getNumberOfTurtles(); i++) {
				if (ptrTurtle[i] != nullptr) {
					if (ptrTurtle[i]->isAdult() && ptrTurtle[i]->canGiveBirth()) {
						foundAdultTurtle = true;
						break;
					}
				}
			}

			if (foundAdultTiger && numberOfBabyTigers > 0) {
				groupWithAdult.push_back(0);	// TIGER = index 0
			}
			if (foundAdultPenguin && numberOfPenguins > 0) {
				groupWithAdult.push_back(1);	// PENGUIN = index 1
			}
			if (foundAdultTurtle && numberOfTurtles > 0) {
				groupWithAdult.push_back(2);	// TURTLE = index 2
			}
			
			// Randomly select a valid group
			if (!groupWithAdult.empty()) {
				selection = groupWithAdult[rand() % groupWithAdult.size()];
			} else {
				selection = -1;
			}

			switch (selection) {
				case TIGER:
					for (int i = 0; i < numberOfTigers; i++) {
						if (ptrTigers[i]->isAdult() && ptrTigers[i]->canGiveBirth()) {
							babyAnimalBorn(TIGER);
							ptrTigers[i]->hadChild();
							break;
						}
					}
					break;
				case PENGUIN:
					for (int i = 0; i < numberOfPenguins; i++) {
						if (ptrPenguin[i]->isAdult() && ptrPenguin[i]->canGiveBirth()) {
							babyAnimalBorn(PENGUIN);
							ptrPenguin[i]->hadChild();
							break;
						}
					}
					break;
				case TURTLE:
					for (int i = 0; i < numberOfTurtles; i++) {
						if (ptrTurtle[i]->isAdult() && ptrTurtle[i]->canGiveBirth()) {
							babyAnimalBorn(TURTLE);
							ptrTurtle[i]->hadChild();
							break;
						}
					}
					break;
				case -1:
					std::cout << "[ERROR NO ADULTS FOUND]..." << std::endl;
					break;
			}
			break;
	}
}

/**
 *	Return the game's current state
 */
std::string Zoo::getGameState() const {
	switch (state) {
		case PLAYING:
			return "PLAYING";
			break;
		case END:
			return "END";
			break;
	}
}

/**
 * Set the game state
 */
void Zoo::setGameState(gameState change) { state = change; }