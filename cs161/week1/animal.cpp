#include <iostream>
#include <string>

/********************************************************************* 
** Author: Tony Huynh
** Date: 
** Description: Read and display user's input to the console.
*********************************************************************/

int main()
{
	std::string faveAnimal;
	std::cout << "Please enter your favorite animal." << std::endl;
	std::cin >> faveAnimal;
	std::cout << "Your favorite animal is the " << faveAnimal;
	std::cout << "." << std::endl;

	return 0;	// main() return type is int (Integer); 0 = success, 1 = failed
}