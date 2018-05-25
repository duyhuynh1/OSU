/*********************************************************************
** Program name: Circular Linked List
** Author: Tony Huynh
** Date: 5/19/2018
** Description: The Queue class provides basic function to traverse,
** add, and remove Nodes from a circular linked list.
*********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
    private:
        struct QueueNode {
            QueueNode *next = nullptr;
            QueueNode *prev = nullptr;
            int val;
        };
        QueueNode *first;
    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        void addBack(int);
        int getFront() const;
        void removeFront();
        void moveFrontToBack();
        void printQueue();
};
#endif  // QUEUE_HPP