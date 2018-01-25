/********************************************************************* 
** Author: Tony Huynh
** Date: 1/24/2018
** Description: Read values from a file and write the sum total to 
** a file named "sum.txt".
*********************************************************************/
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outputFile("sum.txt");
    ifstream inputFile;
    string filename;
    int data = 0;
    int sum = 0;

    cout << "Please enter your filename.\n";
    cin >> filename;
    inputFile.open(filename);
    // Check if inputFile was successfully opened
    if(inputFile) {
        // Reads each value until EOF
        while(inputFile >> data) {
            sum += data;
        }
        outputFile << sum;
        cout << "result written to sum.txt\n";
    } else {
        cout << "could not access file" << endl;
    }
    
    // Clean up
    inputFile.close();
    outputFile.close();
    return 0;
}