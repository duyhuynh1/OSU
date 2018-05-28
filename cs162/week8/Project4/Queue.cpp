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
    std::cout << "Queue::~Queue() called\n";
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
 *  Creates a QueueNode with Character object and pushes it to the
 *  front of the list.
 *  @param player - A Character object stored inside QueueNode object
 */
void Queue::addFront(Character *player) {
    if (first == nullptr) {
        struct QueueNode *newNode = new QueueNode();
        newNode->player = player;
        newNode->next = newNode;
        newNode->prev = newNode;
        first = newNode;
    } else {
        struct QueueNode *last = first->prev;
        struct QueueNode *newNode = new QueueNode();
        newNode->player = player;
        // Link up all Nodes
        newNode->next = first;
        first->prev = newNode;
        newNode->prev = last;
        last->next = newNode;
        first = newNode;
    }
}

/**
 *  Creates a QueueNode with Character object and appends it to the 
 *  back of the list.
 *  @param player - A Character object stored inside QueueNode object
 */
void Queue::addBack(Character *player) {
    // Adding a Node to an empty list
    if (first == nullptr) {
        struct QueueNode *newNode = new QueueNode();
        newNode->player = player;
        newNode->next = newNode;
        newNode->prev = newNode;
        first = newNode;
    } else {
        struct QueueNode *last = first->prev;
        struct QueueNode *newNode = new QueueNode();
        newNode->player = player;
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
Character * Queue::getFront() {
    if (first != nullptr) { return first->player; }
}

/**
 *  Moves the calling Queue's front object to the Queue in argument.
 */
void Queue::moveFrontToFrontOf(Queue *loserPile) {
    loserPile->addFront(this->getFront());
    this->removeFront();
}
/**
 *  Returns the value of the node at the back of the queue.
 */
// int Queue::getBack() const {
//     if (first != nullptr) {
//         std::cout << "The last node value is: " << first->prev->val << std::endl;
//         return 0;   // Success
//     } else {
//         return 1;   // Failed
//     }
// }

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
            delete first->player;
            delete first;
            first = nullptr;
        } else if (second->next == second->prev) {
            delete first->player;
            delete first;
            second->next = second;
            second->prev = second;
            first = second;             // Update first pointer to 2nd Node
        } else {
            struct QueueNode *last = first->prev;
            delete first->player;
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
        // std::cout << "[INFO]: Queue is empty...\n";
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
        do {
            temp->player->getCharacterInfo();
            temp = temp->next;
        } while (temp != first);    // Ends when *temp reaches first again
    } else {
        std::cout << "[INFO]: Queue is empty...\n";
    }
}