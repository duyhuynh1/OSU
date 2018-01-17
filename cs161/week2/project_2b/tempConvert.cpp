/********************************************************************* 
** Author: Tony Huynh
** Date: 1/17/2018
** Description: Temperature conversion calculator. Converts Celcius 
** to Fahrenheit.
*********************************************************************/
#include <iostream>
using namespace std;

int main()
{
	double fahrenheitTemp;
	double celsiusTemp;

	cout << "Please enter a Celsius temperature.\n";
	cin >> celsiusTemp;

	// Temperature Conversion Formula:
	// Calculations must use ONLY type double
	fahrenheitTemp = ((9.0/5.0) * celsiusTemp) + 32.0;
	cout << "The equivalent Fahrenheit temperature is:\n";
	cout << fahrenheitTemp << endl;
	
	return 0;
}