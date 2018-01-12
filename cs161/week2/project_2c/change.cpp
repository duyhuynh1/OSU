#include <iostream>

using namespace std;
/********************************************************************* 
** Author: Tony Huynh
** Date: 1/18/2018
** Description: 
*********************************************************************/

// Write a program that asks the user for a (integer) number of cents, 
// from 0 to 99, and outputs how many of each type of coin would represent 
// that amount with the fewest total number of coins.  When you run 
// your program, it should match the following format:

// Please enter an amount in cents less than a dollar.
// 87
// Your change will be:
// Q: 3
// D: 1
// N: 0
// P: 2

/********************************************************************* 
** Description:
*********************************************************************/
// NOTE: This program does not handle negative inputs.

int main() 
{
	// Variable Declarations
	const int VALUE_QUARTER = 25,
			  VALUE_DIME = 10,
		      VALUE_NICKLE = 5,
		      VALUE_PENNY = 1;
	int qtyOfQuarters = 0,
		qtyOfDimes = 0,
		qtyOfNickles = 0,
		qtyOfPennies = 0,
		numberOfCents = 0;

	cout << "Please enter an amount in cents less than a dollar\n";
	cin >> numberOfCents;

	/* Calculations Example:
	 * Given 0.90 cents = (int) 90
	 * Integer division removes the remainder; anything after "."
	 * Quantity of quarters = 90 / 25 = 3.6 = 3
	 * Using modulus "%" we store the remainder in numberOfCents
	 */
	qtyOfQuarters = numberOfCents / VALUE_QUARTER;
	numberOfCents %= VALUE_QUARTER;
	if (numberOfCents != 0) {
		qtyOfDimes = numberOfCents / VALUE_DIME;
		numberOfCents %= VALUE_DIME;
		if (numberOfCents != 0) {
			qtyOfNickles = numberOfCents / VALUE_NICKLE;
			numberOfCents %= VALUE_NICKLE;
			if (numberOfCents != 0) {
				qtyOfPennies = numberOfCents / VALUE_PENNY;
			} else {
				/* empty statement*/
			}
		} else {
			/* empty statement*/
		}
	} else {
		/* empty statement*/
	}

	// RESULTS
	cout << "Q: " << qtyOfQuarters << endl;
	cout << "D: " << qtyOfDimes << endl;
	cout << "N: " << qtyOfNickles << endl;
	cout << "P: " << qtyOfPennies << endl;
	return 0;
}