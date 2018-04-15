/*********************************************************************
** Program name: File I/O
** Author: Tony Huynh
** Date: 04/15/2018
** Description: ????
*********************************************************************/
#include "file_io.hpp"

/**
 *	
 *	@param input ???
 *	@param frequency ???
 */
void count_letters(std::ifstream &input, int *frequency) {
	int freqArray[26] = {};
	frequency = freqArray;
	std::ofstream outputFile;
	std::string line;

	while (std::getline(input, line)) {
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);
		if (!line.empty()) {	// Handles the newlines
			for (char letter = 'a'; letter <= 'z'; letter++) {
				int total = 0;	// Reset letter frequency count 
				for (int i = 0; i < line.size(); i++) {
					if (line[i] == letter) {
						total += 1;
					}
				}
				*frequency = total;
				frequency++;
			}
			frequency = freqArray;	// Reset the pointer to the beginning of array
			output_letters(outputFile, frequency);
		}
	}
}

/**
 *	
 *	@param output ???
 *	@param frequency ???
 */
void output_letters(std::ofstream &output, int *frequency) {
	std::string outputFilename = "";
	std::cout << "Please enter name for output file: ";
	std::cin >> outputFilename;
	output.open(outputFilename);
	for (char letter = 'a'; letter <= 'z'; letter++) {
		output << letter << ": " << *frequency << std::endl;	// TODO: proper way to send endl???
		frequency++;
	}
	output.close();
}