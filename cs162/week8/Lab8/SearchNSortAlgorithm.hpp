/*********************************************************************
** Program name: Searching and Sorting
** Author: Tony Huynh
** Date: 5/27/2018
** Description: Prototype for the functions that allows the user to 
** simple search, sort, and binary search.
*********************************************************************/
#ifndef SEARCH_N_SORT_ALGORITHM
#define SEARCH_N_SORT_ALGORITHM

#include <iostream>

int simpleSearch(const std::vector<int>, const int &);
void swap(int *, int *);
void simpleSort(const std::string filename, std::vector<int>);
int binarySearch(std::vector<int>, const int &);

#endif  // SEARCH_N_SORT_ALGORITHM