#include "Queue.hpp"

/**
 *  Queue class default constructor
 */
Queue::Queue() {
    std::cout << "Queue::Queue called()\n";
    first = nullptr;
}

/**
 *  Queue class default destructor
 */
Queue::~Queue() {
    // std::cout << "Queue::~Queue called()\n";
    // while (!isEmpty()) {

    // }
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
        std::cout << "case#1: Adding a Node to an empty list\n";    // REMOVE
        struct QueueNode *newNode = new QueueNode();
        newNode->val = val;
        newNode->next = newNode;
        newNode->prev = newNode;
        first = newNode;
    } else {
        std::cout << "case#2: Adding a Node to a non-empty List\n"; // REMOVE
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
    std::cout << "Queue::getFront() called\n";  // REMOVE
    if (first != nullptr) {
        return first->val;
    } else {
        std::cout << "Queue is empty...\n";
        return 0;
    }
}

/**
 *  Removes the front QueueNode of the queue and free the memory
 */
void Queue::removeFront() {
    struct QueueNode *temp = first;
    if (isEmpty()) {
        std::cout << "Queue is empty...\n";
    } else {
        struct QueueNode *second = temp->next;
        if (second == first) {
            std::cout << "Queue has single Node...deleting Node\n";
            delete first;
            first = nullptr;
        } else if (second == first->prev) {
            std::cout << "Queue has two Nodes...deleting first Node\n";
            
        } else {
            std::cout << "Queue has 3+ Nodes...deleting first Node\n";
            // TODO:
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
            std::cout << "Queue has a Node\n";
            std::cout << temp->val << " ";
            temp = temp->next;
        } while (temp != first);    // Ends when *temp reaches first again
    } else {
        std::cout << "Queue is empty...\n";
    }
}