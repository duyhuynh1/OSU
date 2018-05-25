/*********************************************************************
** Program name: Circular Linked List
** Author: Tony Huynh
** Date: 5/19/2018
** Description: The Queue class implements the following functions:
** check if Queue is empty, add a new node to the back, return the
** value of the first Node, remove the first Node, and print the 
** current Queue.
*********************************************************************/
#include "Queue.hpp"

/**
 *  Queue class default constructor
 */
Queue::Queue() {
    first = nullptr;
}

/**
 *  Queue class default destructor.
 */
Queue::~Queue() {
    while (!isEmpty()) {
        removeFront();
    }
}

/**
 *  Checks if the queue is empty. If so, returns true;
 *  otherwise, return false.
 */
bool Queue::isEmpty() const {
    return (first == nullptr) ? true : false;
}

/**
 *  Creates a QueueNode with user­inputted integer, and appends it to the 
 *  back of the list.
 *  @param val integer value stored inside QueueNode object
 */
void Queue::addBack(int val) {
    // Adding a Node to an empty list
    if (first == nullptr) {
        struct QueueNode *newNode = new QueueNode();
        newNode->val = val;
        newNode->next = newNode;
        newNode->prev = newNode;
        first = newNode;
    } else {
        struct QueueNode *last = first->prev;
        struct QueueNode *newNode = new QueueNode();
        newNode->val = val;
        // Link up all Nodes
        first->prev = newNode;
        last->next = newNode;
        newNode->prev = last;
        newNode->next = first;
    }
}

/**
 *  Returns the value of the node at the front of the queue.
 */
int Queue::getFront() const {
    if (first != nullptr) {
        std::cout << "The first node value is: " << first->val << std::endl;
        return 0;   // Success
    } else {
        return 1;   // Failed
    }
}

/**
 *  Removes the front QueueNode of the queue and free the memory
 */
void Queue::removeFront() {
    struct QueueNode *temp = first; // Do we even need this?
    if (isEmpty()) {
        std::cout << "[INFO]: Queue is empty...\n";
    } else {
        struct QueueNode *second = temp->next;
        if (second == first) {
            delete first;
            first = nullptr;
        } else if (second->next == second->prev) {
            delete first;
            second->next = second;
            second->prev = second;
            first = second;             // Update first pointer to 2nd Node
        } else {
            struct QueueNode *last = first->prev;
            delete first;
            first = second;
            second->prev = last;
            last->next = first;
        }
    }
}

/**
 *  Move the first object in the Queue to the end of the Queue.
 *  Example: 1 2 3 -> moveFrontToBack() -> 2 3 1
 */
void Queue::moveFrontToBack() {
    if (isEmpty()) {
        std::cout << "[INFO]: Queue is empty...\n";
    } else { 
        struct QueueNode *second = first->next;
        if (first != second) {  // For Queue sizes >= 2, point first to second.
            first = second;     // All other node connections stay the same.
        }
    }
}

/**
 *  Traverses through the queue from first using next pointers, and prints 
 *  the values of each QueueNode in the queue.
 */
void Queue::printQueue() {
    struct QueueNode *temp = first;
    // Check if the Queue is empty
    if (temp != nullptr) {
        std::cout << "Your queue is: ";
        do {
            std::cout << temp->val << " ";
            temp = temp->next;
        } while (temp != first);    // Ends when *temp reaches first again
    } else {
        std::cout << "[INFO]: Queue is empty...\n";
    }
}