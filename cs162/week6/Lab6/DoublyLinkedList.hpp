/*********************************************************************
** Program name: Doubly-Linked List
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Doubly-Linked List class provides the functions
** used to add, delete, and traverse a Linked List.
*********************************************************************/
#ifndef	DOUBLY_LINKED_LIST_HPP
#define	DOUBLY_LINKED_LIST_HPP

#include <iostream>
#include "Node.hpp"

enum StartFrom { HEAD, TAIL };

class DoublyLinkedList {
	private:
		Node *head;
		Node *tail;
	public:
		DoublyLinkedList();
		~DoublyLinkedList();
		void add(int, StartFrom);
		void remove(StartFrom);
		void printList(StartFrom);
};
#endif	// DOUBLY_LINKED_LIST_HPP