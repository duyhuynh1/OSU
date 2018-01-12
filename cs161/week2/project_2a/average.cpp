#include <iostream>

using namespace std;
/********************************************************************* 
** Author: Tony Huynh
** Date: 1/18/2018
** Description: Calculates the average value of five numbers.
*********************************************************************/

// TODO: Write a program that asks the user for five numbers and then prints 
// out the average of those numbers.  When you run your program, it should match the following format:

// Please enter five numbers.
// -2.4
// 5.1
// 6.0
// 123.8
// -19.0
// The average of those numbers is:
// 22.7

/********************************************************************* 
** Description:
*********************************************************************/ 
int main()
{
	// Variable declaration 
	const int NUMBER_OF_INPUT = 5;
	double sum;
	double average;

	// cout << "Please enter five numbers\n";
	// OPTION 1:
	// cin >> input1;
	// cin >> input2;
	// cin >> input3;
	// cin >> input4;
	// cin >> input5;
	// average = (input1 + input2 + input3 + input4 + input5) / 5;

	// OPTION 2:
	cout << "Please enter five numbers\n";
	for (int i = 0; i < NUMBER_OF_INPUT; i++) 
	{
		double userInput;
		cin >> userInput;
		sum += userInput;
	}
	average = sum / NUMBER_OF_INPUT;

	// OPTION 3:
	// Create an average() function to handle user input;
	cout << "The average of those numbers is:\n" << average << endl;

	return 0;
}