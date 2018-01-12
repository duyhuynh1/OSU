#include <iostream>

using namespace std;
/********************************************************************* 
** Author: Tony Huynh
** Date: 1/18/2018
** Description: 
*********************************************************************/

// Formula: F = 9/5*C + 32
// Please enter a Celsius temperature.
// -10.5
// The equivalent Fahrenheit temperature is:
// 13.1

/********************************************************************* 
** Description:
*********************************************************************/
int main()
{
	// Variable Declaration
	double fahrenheitTemp;
	double celsiusTemp;

	cout << "Please enter a Celsius temperature." << endl;
	cin >> celsiusTemp;

	// Temperature Conversion Formula
	// NOTE: Calc must use ONLY type double
	fahrenheitTemp = ((9.0/5.0) * celsiusTemp) + 32.0;
	cout << "The equivalent Fahrenheit temperature is:\n";
	cout << fahrenheitTemp << endl;
	
	return 0;
}