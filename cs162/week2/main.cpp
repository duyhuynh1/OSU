/*********************************************************************
** Program name: File I/O Driver
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ????
*********************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include "file_io.hpp"

int main() {
	std::string inputFilename = "";
	int * frequencyCounter = NULL;
	bool success = false;

	std::ifstream inputFile;
	std::ofstream outputFile;

	do {
		std::cout << "Please enter name of file to read: ";
		std::cin >> inputFilename;
		inputFile.open(inputFilename);
		if (inputFile) {
			success = true;
		} else {
			std::cout << "Error: cannot open \'" + inputFilename + "\'" << std::endl;
		}
	} while (!success);
	
	count_letters(inputFile, frequencyCounter);

	// Clean up
	inputFile.close();

	return 0;
}