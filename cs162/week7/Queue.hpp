#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
    struct QueueNode {
        QueueNode *next = nullptr;
        QueueNode *prev = nullptr;
        int val;
    };
    private:
        QueueNode *first;
    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        void addBack(int);
        int getFront() const;
        void removeFront();
        void printQueue();
};
#endif  // QUEUE_HPP