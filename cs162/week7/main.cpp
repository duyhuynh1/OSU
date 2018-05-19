#include <iostream>
#include "Queue.hpp"

int main() {
    Queue *mQueue = new Queue();
    int num1 = 10;
    int num2 = 11;
    int num3 = 12;
    mQueue->addBack(num1);
    mQueue->addBack(num2);
    mQueue->addBack(num3);
    mQueue->printQueue();

    std::cout << "front: " << mQueue->getFront();
    mQueue->removeFront();
    delete mQueue;
    return 0;
}