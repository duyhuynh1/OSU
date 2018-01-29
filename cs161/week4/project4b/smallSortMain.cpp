/*************************
** Used to unit test code
*************************/
#include <iostream>

// Function prototype
void smallSort(int &a, int &b, int &c);

int main() {
    int a = 14;
    int b = -90;
    int c = 2;
    smallSort(a, b, c);
    std::cout << a << ", " << b << ", " << c << std::endl;

    return 0;
}