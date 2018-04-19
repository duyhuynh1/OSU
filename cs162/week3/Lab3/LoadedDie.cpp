#include "Die.hpp"
#include "LoadedDie.hpp"

LoadedDie::LoadedDie(int side) : Die(side) {
    std::cout << "Loaded Die constructor" << std::endl; // REMOVE
}

// @Override
int LoadedDie::roll() {
    std::cout << "LoadedDie::roll()" << std::endl;
    srand(time(NULL));
    int firstRollValue = (rand() % numberOfSides) + 1;
    int secondRollValue = (rand() % numberOfSides) + 1;
    std::cout << "firstRollValue = " << firstRollValue << std::endl;
    std::cout << "secondRollValue = " << secondRollValue << std::endl;
    if (firstRollValue == secondRollValue) {
        return firstRollValue;
    } else if (firstRollValue > secondRollValue) {
        return firstRollValue;
    } else if (firstRollValue < secondRollValue) {
        return secondRollValue;
    }
}