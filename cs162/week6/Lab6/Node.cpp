/*********************************************************************
** Program name: Doubly-Linked List
** Author: Tony Huynh
** Date: 5/13/2018
** Description: The Node class provides functions to add, remove, and
** get values from a Linked list. Node objects are joined together to
** create a List containing integers.
*********************************************************************/
#include "Node.hpp"

/**
 *	Node class default constructor
 *	@param val Integer value the specific Node contains
 */
Node::Node(int val) { 
	this->val = val;
	next = nullptr;
	prev = nullptr;
}