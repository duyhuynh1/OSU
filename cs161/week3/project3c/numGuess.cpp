/********************************************************************* 
** Author: Tony Huynh
** Date: 1/24/2018
** Description: Number guesing game that provides the user feedback 
** to whether the user's guess was too high or too low.
*********************************************************************/
#include <iostream>
using namespace std;

int main() {
    int correctNumber, userGuessNumber;
    int numberOfTries = 0;
    bool done = false;
    
    cout << "Enter the number for the player to guess.\n";
    cin >> correctNumber;
    cout << "Enter your guess.\n";
    cin >> userGuessNumber;
    // Repeats loop until user guesses correctNumber
    while(!done) {
        // Add 1 to numberOfTries everytime user is inside while loop
        numberOfTries++;
        if(userGuessNumber == correctNumber) {
            // Set boolean to true to exit while loop
            done = true;
        } else if(userGuessNumber > correctNumber) {
            cout << "Too high - try again.\n";
            cin >> userGuessNumber;
        } else if(userGuessNumber < correctNumber) {
            cout << "Too low - try again.\n";
            cin >> userGuessNumber;
        }
    }
    cout << "You guessed it in " << numberOfTries << " tries." << endl;
    return 0;
}