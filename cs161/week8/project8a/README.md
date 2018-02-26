# Project 8a

## Requirements:
Write a void function named smallSort2 that takes as parameters the addresses of three int variables and sorts the ints at those addresses into ascending order. For example if the main method has:

	`
	int first = 14;
	int second = -90;
	int third = 2;
	smallSort2(&first, &second, &third);
	cout << first << ", " << second << ", " << third << endl;
	`
Then the output should be:
	`
	-90, 2, 14
	`
This can be very similar to your previous smallSort program, but uses pointers instead of references.

The file must be named smallSort2.cpp.

## Todo List: