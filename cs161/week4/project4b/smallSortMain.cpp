/*************************
** Used to unit test code
*************************/
#include <iostream>

// Function prototype
void smallSort(int &a, int &b, int &c);

int main() {
    int a;
    int b;
    int c;
    std::cout << "a: ";
    std::cin >> a;
    std::cout << "b: ";
    std::cin >> b;
    std::cout << "c: ";
    std::cin >> c;
    smallSort(a, b, c);
    std::cout << a << ", " << b << ", " << c << std::endl;

    return 0;
}