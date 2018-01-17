/********************************************************************* 
** Author: Tony Huynh
** Date: 1/17/2018
** Description: Calculates the fewests number of coins needed to
** represent the number of cents chosen by the user.
*********************************************************************/
#include <iostream>
using namespace std;

int main() 
{
	const int VALUE_QUARTER = 25,
			  VALUE_DIME = 10,
		      VALUE_NICKLE = 5,
		      VALUE_PENNY = 1;
	int qtyOfQuarters = 0,
		qtyOfDimes = 0,
		qtyOfNickles = 0,
		qtyOfPennies = 0,
		numberOfCents = 0;

	cout << "Please enter an amount in cents less than a dollar.\n";
	cin >> numberOfCents;

	/* Calculations Example:
	 * Given 0.90 cents = (int) 90
	 * Integer division removes the remainder; anything after "."
	 * Quantity of quarters = 90 / 25 = 3.6 = 3
	 * Using modulus "%" we store the remainder in numberOfCents.
	 * %= is equivalent to using, numberOfCents -= qtyOf<coin> * VALUE_<coin>
	 */
	qtyOfQuarters = numberOfCents / VALUE_QUARTER;
	numberOfCents %= VALUE_QUARTER;
	// Check if numberOfCent is above 0 after subtracting the previous coin value
	// If TRUE, repeat procedure with the next highest value coin until numberOfCent reaches 0
	if (numberOfCents > 0) {
		qtyOfDimes = numberOfCents / VALUE_DIME;
		numberOfCents %= VALUE_DIME;
		if (numberOfCents > 0) {
			qtyOfNickles = numberOfCents / VALUE_NICKLE;
			numberOfCents %= VALUE_NICKLE;
			if (numberOfCents > 0) {
				qtyOfPennies = numberOfCents / VALUE_PENNY;
			} else {
				// empty statement
			}
		} else {
			// empty statement
		}
	} else {
		// empty statement
	}

	// RESULTS
	cout << "Your change will be:\n";
	cout << "Q: " << qtyOfQuarters << endl;
	cout << "D: " << qtyOfDimes << endl;
	cout << "N: " << qtyOfNickles << endl;
	cout << "P: " << qtyOfPennies << endl;
	return 0;
}