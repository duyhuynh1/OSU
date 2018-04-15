/*********************************************************************
** Program name: File I/O
** Author: Tony Huynh
** Date: 04/15/2018
** Description: File I/O is a program that reads a file filled with 
** letters, count the letter frequencies in the file, and write the 
** results to a new file.
*********************************************************************/
#ifndef FILE_IO_HPP
#define FILE_IO_HPP

#include <iostream>		// REMOVE
#include <fstream>
#include <algorithm>

void count_letters(std::ifstream &, int*);
void output_letters(std::ofstream &, int*);

#endif	// FILE_IO.HPP