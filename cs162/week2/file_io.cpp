/*********************************************************************
** Program name: File I/O
** Author: Tony Huynh
** Date: 04/15/2018
** Description: File I/O functions implemented. These two functions 
** together reads a file and tallies up the frequency of letters, and
** then writes the results of each paragraph into a new file.
*********************************************************************/
#include "file_io.hpp"

/**
 *	Reads the paragraph string from the input file stream, then
 *	counts the letter frequencies of that paragraph, and stores the
 *	results in an integer array.
 *	@param input An input file stream used to read data from a file
 *	@param frequency A pointer to an integer array containing 
 *	frequency data
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
 *	Prompts the user for output filename and writes the frequencies of
 *	letters to the specified file.
 *	@param output An output file stream used to write data to a file
 *	@param frequency A pointer to an integer array containing 
 *	frequency data
 */
void output_letters(std::ofstream &output, int *frequency) {
	std::string outputFilename = "";
	bool success = false;
	do {
		std::cout << "Please enter name for output file: ";
		std::getline(std::cin, outputFilename);
		if (outputFilename.size() != 0) {
			output.open(outputFilename);
			for (char letter = 'a'; letter <= 'z'; letter++) {
				output << letter << ": " << *frequency << std::endl;
				frequency++;
			}
			success = true;
			output.close();		// Clean up
		}
	} while (!success);
}