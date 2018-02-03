/*************************
** Used to unit test code
*************************/
#include <iostream>

// Function prototype
void smallSort(int &a, int &b, int &c);

int main() {
    int a = -1;
    int b = -10;
    int c = -10;
    smallSort(a, b, c);
    std::cout << a << ", " << b << ", " << c << std::endl;

    return 0;
}