/*********************************************************************
** Program name: Doubly-Linked List
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Doubly-Linked List class implements the functions
** used to add, delete, and traverse a Linked List.
*********************************************************************/
#include "DoublyLinkedList.hpp"

/**
 *	Doubly-Linked List default constructor
 */
DoublyLinkedList::DoublyLinkedList() { 
	head = nullptr;
	tail = nullptr;
}

/**
 *	Doubly-Linked List default destructor
 */
DoublyLinkedList::~DoublyLinkedList() {
	// Delete starting from List Head
	Node *nodeTraversePtr = head;
	while (nodeTraversePtr != nullptr) {
		Node *node = nodeTraversePtr;
		nodeTraversePtr = nodeTraversePtr->next;
		delete node;
	}
}

/**
 *	Doubly-Linked List add function inserts a Node object in a specified direction
 *	@param value An integer that will be stored by Node object
 *	@param direction An enum depiciting which direction the Node will be inserted
 */
void DoublyLinkedList::add(int value, StartFrom direction) {
	Node *newNode = new Node(value);	// Create a new Node object
	if (head == nullptr || tail == nullptr) {
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;			// New Node object next points to nullptr
		newNode->prev = nullptr;			// New Node object prev points to nullptr
	} else {
		switch (direction) {
			case HEAD:
				newNode->next = head;		// Node object next points to head
				head->prev = newNode;		// Previous Node object points to new Node object
				head = newNode;				// List head points to new Node object
				break;
			case TAIL:
				newNode->prev = tail;		// Node object previous points to tail
				tail->next = newNode;		// Next Node object points to new Node object
				tail = newNode;				// List tail points to new Node object
				break;
		}
	}
}

/**
 *	Doubly-Linked List remove function deletes a Node object from specified direction
 *	@param direction An enum depiciting which end a Node will be removed from
 */
void DoublyLinkedList::remove(StartFrom direction) {
	if (head == nullptr || tail == nullptr) {
		return;
	} else {
		switch (direction) {
			case HEAD:
				if (head->next == nullptr && head->prev == nullptr) {
					delete head;
					head = nullptr;
					tail = nullptr;
				}
				if (head != nullptr) {
					Node *temp = head;		// Create a Node pointer to store Node obj pointed to by head
					head = temp->next;		// Head points to next node object
					head->prev = nullptr;	// New head prev pointer points to nullptr
					delete temp;			// Now we can delete it
				}
				break;
			case TAIL:
				if (tail->next == nullptr && tail->prev == nullptr) {
					delete tail;
					tail = nullptr;
					head = nullptr;
				} 
				if (tail != nullptr) {
					Node *temp = tail;		// Create a Node pointer to store Node obj pointed to by tail
					tail = temp->prev;		// Tail points to prev node object
					tail->next = nullptr;	// New tail pointer points to nullptr
					delete temp;			// Now we can delete it
				}
				break;
		}
	}
}

/**
 *	Prints the Linked List starting from the Head or Tail
 *	@param direction An enum indicating which direction to start traversing
 */
void DoublyLinkedList::printList(StartFrom direction) {
	Node *nodeTraversePtr;
	if (head == nullptr || tail == nullptr) {
		std::cout << "[INFO]: List is empty...\n";
	} else {
		std::cout << "[Linked List]: ";
		switch (direction) {
			case HEAD:
				nodeTraversePtr = head;
				while (nodeTraversePtr) {
					std::cout << nodeTraversePtr->val << " ";
					nodeTraversePtr = nodeTraversePtr->next;
				}
				break;
			case TAIL:
				nodeTraversePtr = tail;
				while (nodeTraversePtr) {
					std::cout << nodeTraversePtr->val << " ";
					nodeTraversePtr = nodeTraversePtr->prev;
				}
				break;
		}		
	}
	std::cout << "\n";
}

/**
 *	Prints the Node in the specified direction
 *	@param direction An enum indicating which end the function will print
 */
void DoublyLinkedList::print(StartFrom direction) {
	Node *nodePtr;
	if (head == nullptr || tail == nullptr) {
		std::cout << "[INFO]: List is empty...\n";
	} else {
		switch (direction) {
			case HEAD:
				nodePtr = head;
				std::cout << "[List Head]: " << nodePtr->val << "\n";
				break;
			case TAIL:
				nodePtr = tail;
				std::cout << "[List Tail]: " << nodePtr->val << "\n";
				break;
		}
	}
}

/**
 *	Create a linked list structure based off data from a file
 *	Import appends the data to the linked list from the head
 *	@param filename A string representing the file storing the data
 */
void DoublyLinkedList::import(std::string filename) {
	std::ifstream input;
	bool success = false;
	int number;
	do {
		input.open(filename);
		if (input) {
			std::string value;
			while (std::getline(input, value)) {
				number = stoi(value);
				add(number, HEAD);
			}
			success = true;
		}
	} while (!success);
	input.close();
}