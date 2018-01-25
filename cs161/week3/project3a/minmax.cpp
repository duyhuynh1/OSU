/*********************************************************************
** Author: Tony Huynh
** Date: 1/24/2018
** Description: Determine the min and max values of a group of 
** integers provided by the user.
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
	int qtyIntegers, userInput, minInteger, maxInteger;
	
	cout << "How many integers would you like to enter?\n";
	cin >> qtyIntegers;
	cout << "Please enter " << qtyIntegers << " integers.\n";

	// Must account for when user inputs only 1 integer.
	cin >> userInput;
	if(qtyIntegers == 1) {
		minInteger = maxInteger = userInput;
	} else {
		// Assigns minInteger and maxInteger values 
		cin >> minInteger;
		if(userInput > minInteger) {
			maxInteger = userInput;
		} else {
			maxInteger = minInteger;
			minInteger = userInput;
		}
		// Handles qtyInteger greater than 2.
		for(int i = 0; i < qtyIntegers - 2; i++) {
			cin >> userInput;
			if(userInput > maxInteger) {
				maxInteger = userInput;
			} else if(userInput < minInteger) {
				minInteger = userInput;
			}
		}
	}

	cout << "min: " << minInteger << endl;
	cout << "max: " << maxInteger << endl;

	return 0;
}