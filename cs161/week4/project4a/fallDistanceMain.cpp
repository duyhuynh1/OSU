/*************************
** Used to unit test code
*************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Prototype functions
double fallDistance(double);

int main() {
    // Initializing array of double
    double assert[] = { 0.0, 1.0, 2.0, 3.2, 5.8 },
           expect[] = { 0.0, 4.9, 19.6, 50.1760000000000161435309564694762229919433593750000000000000000000000000000000000000000000000000000000, 164.836 };

    int assertSize = sizeof(assert) / sizeof(assert[0]);

    // cout << fixed << showpoint << setprecision(100) << expect[3] << endl;
    // cout << fixed << showpoint << setprecision(100) << fallDistance(assert[3]);
    // if(expect[3] == fallDistance(assert[3])) {
    //     cout << "[PASS]" << endl;
    // } else {
    //     cout << "[FAIL]" << endl;
    // }
    for(int i = 0; i < assertSize; i++) {
        double input = assert[i];
        double result = fallDistance(input);
        double answer = expect[i];
        if(result == answer) {
            cout << "\nTest#:" << i << " [PASS]\n";
            cout << "assert: " << assert[i];
            cout << " , expected: " << expect[i];
            cout << " , result: " << result;
        } else {
            cout << "\nTest#:" << i << " [FAIL]\n";
            cout << "assert: " << assert[i];
            cout << " , expected: " << expect[i];
            cout << " , result: " << result;
        }
    }
    
    return 0;
}