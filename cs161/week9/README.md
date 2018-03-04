# Assignment 9
Due Wednesday by 11:55pm  Points 60
## Requirements
 - Write a class called **Board** that represents a tic-tac-toe board.
	 - It should have a 3x3 array of chars ('x', 'o', or a space, where a space would represent an empty square) as a data member, which will store the locations of the players' moves.
	 - It should have a default constructor that initializes the 3x3 array to being empty (each element set to a space character).
	 - It should have a method called **makeMove()** that takes two ints and a char (either 'x' or 'o') as parameters, representing the x and y coordinates of the move (see the example below) and which player's turn it is.
		 - If that location is unoccupied, makeMove should record the move and return **true**.
		 - If that location is already occupied, makeMove should just return **false**.
	 - There should be a method called gameState that takes no parameters and returns one of the four following values:
		 - **X_WON** , **O_WON**, **DRAW**, or **UNFINISHED**
use an enum for this, not strings (the enum definition should go in Board.hpp, before the class, not inside it). 
 - [**Optional:** write a method called print, which just prints out the current board to the screen - this is not required, but will very likely be useful for debugging.]
 
 - Write a class called **T3Reader** that uses the Board class to re-run a game of TicTacToe from moves that it reads from a text file.
	 - This class will have a field for a Board object and a field to keep track of which player's turn it is.
	 - It should have a constructor that takes a char parameter that specifies whether 'x' or 'o' should have the first move.
	 - It should have a method called **readGameFile()** that takes a string parameter that gives the name of the game file.
	 - The readGameFile method should keep looping, reading a move from the file, and sending it to the board (with makeMove).
		 -  The readGameFile method should return false if any of the moves is for a square that was already occupied, or if there are still additional moves in the file after the game has finished. 
		 - Otherwise it should return **true**. 
> Make sure you close the input file in every case.

Here's an example of the format for the text file:

0 1
2 1
2 0
1 2

and so on.  Which coordinate is the row and which is the column doesn't matter as long as you're consistent.

 The files must be named: **Board.cpp**, **Board.hpp**, **T3Reader.cpp**, **T3Reader.hpp**.