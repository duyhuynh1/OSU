/*********************************************************************
** Author: Tony Huynh
** Date: 1/31/2018
** Description: Calculates the hailstone sequence starting from the
** user's selected positive integer. The program returns the number 
** of steps taken to end up with the number 1.
*********************************************************************/
// #include <iostream>

int getNextSequence(int num);

int hailstone(int num) {
	int steps = 0;

	while(num != 1) {
		num = getNextSequence(num);
		steps++;
	}
	// Returns steps = 0, if initial num = 1
	return steps;
}

int getNextSequence(int num) {
	int result;
	if(num % 2 == 0) {
		// If n is even, divide it by 2 to give n' = n / 2
		result = num /= 2;
		// std::cout << "[DEBUG]: next = " << result << std::endl;
	} else {
		// If n is odd, multiply it by 3 to give n' = 3n + 1
		result = 3 * num + 1;
		// std::cout << "[DEBUG]: next = " << result << std::endl;
	}
	return result;
}
