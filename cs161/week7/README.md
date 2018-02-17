# Project 7.a
## Requirements
 - Create a function called **findMedian**
		 - @param: *mIntArray* an array of integers
		 - @param: *SIZE* an integer storing the size of an array
		 - @return: *median* the median integer of the array

## Finding the Median
The median is the middle number. To calculate the median of any set of numbers, you need to write the numbers in order.

 - Put all the numbers in **numerical order**.
 - If there is an **odd** number of results, the median is the middle number.
 - If there is an **even** number of results, the median will be the *mean* of the two central numbers.

### Finding the median with an odd number of results
 1. Given an ODD set: 9 13 9 11 9 13 11 9 10 8 11
 2. Put the numbers in numerical order:
	 8 9 9 9 9 10 11 11 11 13 13
 3. Find the middle number:
	 8 9 9 9 9 10 11 11 11 13 13
	The middle number is 10, so the **median is 10**.
### Finding the median with an even number of results
1. Given an EVEN set: 5  11  12  4  8  21
2. Put the numbers in numerical order:
	4  5  8  11  12  21.
3. Find the middle number or numbers:
	4  5  8  11  12  21.
4. *If there are two central numbers, we need to find their mean.
	The median is therefore:
	> (8 + 11) ÷ 2 = 9.5

The file must be named: findMedian.cpp.