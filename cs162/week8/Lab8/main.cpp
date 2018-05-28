/*********************************************************************
** Program name: Searching and Sorting
** Author: Tony Huynh
** Date: 5/27/2018
** Description: The driver class displays the results of a basic
** simple search, sort, and binary search algorithm.
*********************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <stdexcept>
#include "SearchNSortAlgorithm.hpp"

int main() {
    const std::string filename1 = "num.txt";
    const std::string filename2 = "early.txt";
    const std::string filename3 = "middle.txt";
    const std::string filename4 = "end.txt";
    const int SIZE = 4;

    std::string filenameList[SIZE] = { filename1, filename2, filename3, filename4 };
    std::ifstream input;
    std::vector<int> data{};
    std::vector<std::string> outputFilenameList{};
    int key;    // Key value that will be searched

    std::string number;
    std::size_t found;
    int result;
    bool valid = false;
    do {
        try {
            std::cout << "What is key value: " << std::flush;
            std::getline(std::cin, number);
            found = number.find_first_not_of("1234567890-");
            if (found == std::string::npos) {
                result = std::stoi(number);
                if (result >= INT_MIN && result <= INT_MAX) {
                    key = result;
                    valid = true;
                }
            }
        } catch (std::invalid_argument) {
            // Invalid argument exeception caught (e.g., " ")
        } catch (std::out_of_range) {
            // Out of range exception caught
        }
    } while (!valid);


    // Linear search algorithm demonstration
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Simple (Linear) search algorithm" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    for (int i = 0; i < SIZE; i++) {
        input.open(filenameList[i]);
        if (input) {
            int value = 0;
            while (input >> value) {
                data.push_back(value);
            }
            if (simpleSearch(data, key) == 0) {
                std::cout << filenameList[i] << ": target value FOUND\n";
            } else {
                std::cout << filenameList[i] << ": target value NOT FOUND\n";
            }
        } else {
            std::cout << "[E]: " << filenameList[i] << " file not found\n";
        }
        data.clear();       // Clear vector
        input.close();      // Close current file
    }

    // Bubble sort algorithm demostration
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Simple (Bubble) sort algorithm demo" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    std::string filename = "";
    for (int i = 0; i < SIZE; i++) {
        bool done = false;
        std::cout << "Sorting file \"" << filenameList[i] << "\"\n";
        do {
            std::cout << "Enter output filename: ";
            std::getline(std::cin, filename);
            if (filename.length() > 0) {
                outputFilenameList.push_back(filename);
                input.open(filenameList[i]);
                if (input) {
                    int value = 0;
                    while (input >> value) {
                        data.push_back(value);
                    }
                    simpleSort(filename, data);
                } else {
                    std::cout << "[E]: " << filenameList[i] << " file not found\n";
                }
                data.clear();
                input.close();
                // Ouput the sorted data
                std::cout << "Sorted output file " << filename << ": ";
                std::ifstream ouputData(filename);
                int sortedValue;
                while (ouputData >> sortedValue) {
                    std::cout << sortedValue << " ";
                }
                std::cout << "\n";
                ouputData.close();
                done = true;
            } else {
                std::cout << "[E]: filename cannot be empty\n";
            }
        } while (!done);
    }

    // Binary search algorithm
    // Note: Using sorted output files
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "Binary search algorithm" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    for (int i = 0; i < SIZE; i++) {
        input.open(outputFilenameList[i]);
        if (input) {
            int value = 0;
            while (input >> value) {
                data.push_back(value);
            }
            if (binarySearch(data, key) == 0) {
                std::cout << filenameList[i] << ": target value FOUND\n";
            } else {
                std::cout << filenameList[i] << ": target value NOT FOUND\n";
            }
        } else {
            std::cout << "[E]: " << filenameList[i] << " file not found\n";
        }
        data.clear();
        input.close();
    }

    return 0;
}