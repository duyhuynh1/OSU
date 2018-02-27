# Project 8.b

## Requirements
Write a void function called transformArray that takes two parameters 
- a reference to a pointer to a dynamically allocated array of ints,
 and the size of that array.  The pointer is passed by reference 
 because you want to change the value of the pointer.  
 The function should replace the array with one that is twice as long, 
 with the values from the original array followed by each of those values 
 plus one.  For example, if array that was passed in was {4, 2, 5}, 
 then it should be replaced by {4, 2, 5, 5, 3, 6}.  The function should 
 prevent any memory leaks.  Remember to also prevent memory leaks in 
 the main you use for testing.

For example, it could be used like this:
`
   int* myArray = new int[3];
   myArray[0] = 4;
   myArray[1] = 2;
   myArray[2] = 5;

   transformArray(myArray, 3);

   for (int i=0; i<6; i++)
      cout << myArray[i] << endl;

   delete []myArray;
`
The file must be named transformArray.cpp.