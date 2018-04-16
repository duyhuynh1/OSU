/*********************************************************************
** Program name: File I/O Driver
** Author: Tony Huynh
** Date: 04/15/2018
** Description: File I/O driver program. Initializes an input file
** stream and analyzes each paragraph contained in the file for letter
** frequencies. The results are stored in an output file specified by
** the user.
*********************************************************************/
#include <iostream>
#include "file_io.hpp"

int main() {
	std::string inputFilename = "";
	int * frequencyCounter = NULL;
	bool success = false;
	std::ifstream inputFile;

	do {
		std::cout << "Please enter name of file to read: ";
		std::getline(std::cin, inputFilename);
		if (inputFilename.size() != 0) {
			inputFile.open(inputFilename);
			if (inputFile) {
				success = true;
			} else {
				std::cout << "Error: cannot open \'" + inputFilename + "\'" << std::endl;
			}
		}
	} while (!success);
	
	count_letters(inputFile, frequencyCounter);
	inputFile.close();	// Clean up

	return 0;
}