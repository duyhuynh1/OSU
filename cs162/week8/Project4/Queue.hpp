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
#include "Character.hpp"

class Queue {
    private:
        struct QueueNode {
            QueueNode *next = nullptr;
            QueueNode *prev = nullptr;
            Character *player = nullptr;
            // Character player;
        };
        QueueNode *first;
    public:
        Queue();
        ~Queue();
        bool isEmpty() const;
        void addFront(Character *);
        void addBack(Character *);
        Character * getFront();
        void moveFrontToFrontOf(Queue *);
        // int getBack() const;
        void removeFront();
        void moveFrontToBack();
        void printQueue();
};
#endif  // QUEUE_HPP