/********************************************************************* 
** Author: Tony Huynh
** Date: Jan 10, 2018
** Description: Read and display user's input to the console.
*********************************************************************/

#include <iostream>
#include <string>

// a simple example program
int main()
{
	std::string faveAnimal;  // String variable declared 
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;  // User input stored in string variable 
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;	// main() return type is int (Integer); 
}
