/********************************************************************* 
** Author: Tony Huynh
** Date: 1/17/2018
** Description: Calculates the average value of five numbers.
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{
	const double NUMBER_OF_INPUT = 5.0;
	double input1, input2, input3, input4, input5;
	double average;

	cout << "Please enter five numbers.\n";
	cin >> input1;
	cin >> input2;
	cin >> input3;
	cin >> input4;
	cin >> input5;
	average = (input1 + input2 + input3 + input4 + input5) / NUMBER_OF_INPUT;

	cout << "The average of those numbers is:\n" << average << endl;

	return 0;
}