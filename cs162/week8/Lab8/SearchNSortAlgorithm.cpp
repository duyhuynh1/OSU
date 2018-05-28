/*********************************************************************
** Program name: Searching and Sorting
** Author: Tony Huynh
** Date: 5/27/2018
** Description: Implements a simple search, sort, and binary search
** algorithm.
*********************************************************************/
#include <fstream>
#include <vector>
#include "SearchNSortAlgorithm.hpp"

/**
 *  Simple search function implements a basic lineary search algorithm.
 *  It returns 0 if the key value is found. Otherwise -1 if not found.
 *  @param filename - Name of the file the function will parse
 *  @param key - An integer depicting the integer to search for
 */
int simpleSearch(const std::vector<int> data, const int &key) {
    for (int i = 0; i < data.size(); i++) {
        if (key == data[i]) {
            return 0;
        }
    }
    return -1;
}

/**
 *  Swap function used by the simpleSorting function to swap the
 *  positions of two elements in an array.
 *  @param a - An integer depicting an element in an array/vector
 *  @param b - An integer depicting an element in an array/vector
 */
void swap(int *a, int *b) {
    int temp = *a;  // De-referrence pointer
    *a = *b;        // Assign a the value of b
    *b = temp;      // Assign b the value of temp, which stored value of a
}

/**
 *  Simple sorting function implements a basic bubble sort algorithm.
 *  @param data - An input array to which the function parses
 *  REF: https://www.geeksforgeeks.org/bubble-sort/
 */
void simpleSort(const std::string filename, std::vector<int> data) {
    std::ofstream output(filename);
    // Sentinel value used to break out of function
    bool swapped;
    for (int i = 0; i < data.size(); i++) {
        swapped = false;
        for (int j = 0; j < data.size() - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                swap(&data[j], &data[j + 1]);
                swapped = true;
            }
        }
        // If no swaps were performed then array/vector is sorted
        if (swapped == false) {
            break;
        }
    }
    for (int i = 0; i < data.size(); i++) {
        output << data[i] << " ";
    }
    output.close();
}

/**
 *  Binary search function implements the basic binary search algorithm.
 *  Return 0 if key is found. Otherwise -1 if key was not found.
 *  @param data - An integer array to which the function parses
 *  @param key - An integer depicting the integer to search for
 *  REF: https://www.geeksforgeeks.org/binary-search/
 */
int binarySearch(std::vector<int> data, const int &key) {
    // Binary search requires the data to be sorted
    int low = 0;                    // Initial low index
    int high = data.size() - 1;     // Initial high index
    int mid = (low + high) / 2;
    while (low <= high) {
        if (data[mid] == key) {
            return 0;
        }
        // If key value is greater, ignore lower half and search upper half
        if (data[mid] < key) {
            low = mid + 1;
        // If key value is less, ignore upper half and search lower half
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    // If key is not found return -1
    return -1; 
}