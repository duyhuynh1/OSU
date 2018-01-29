#include <iostream>

// Function prototype
int hailstone(int startingInteger);

int main() {
	int userInput;
	int results;
	std::cout << "Enter a number: ";
	std::cin >> userInput;

	results = hailstone(userInput);
	std::cout << "Number of steps: " << results << std::endl;

	return 0;
}