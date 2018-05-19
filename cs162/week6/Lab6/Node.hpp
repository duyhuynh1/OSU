/*********************************************************************
** Program name: Doubly-Linked List
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Node class provides functions to add, remove, and
** get values from a Linked list.
*********************************************************************/
#ifndef NODE_HPP
#define	NODE_HPP

class Node {
	public:
		int val;
		Node *next;
		Node *prev;
		Node(int);
};
#endif	// NODE_HPP