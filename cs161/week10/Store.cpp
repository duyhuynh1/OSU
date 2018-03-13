/*********************************************************************
** Author: Tony Huynh
** Date: 03/14/2018
** Description: A Store object represents a store, which has some 
** number of products in its inventory and some number of customers
** as members.
*********************************************************************/
#include <iostream>	// REMOVE
#include <algorithm>
#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"

/**
 *	Add a Product object to the Store's inventory
 */
void Store::addProduct(Product * p) { inventory.push_back(p); }

/**
 *	Add a Customer object to the Store's 
 */
void Store::addMember(Customer * c) { members.push_back(c); }

/**
 *	Find a Product using the ID Code as a search parameter
 *
 *	@param searchIDCode is a string used as a search parameter
 *	@return pointer to Product Object with matching ID Code
 */
Product * Store::getProductFromID(std::string searchIDCode) {
	for (Product * item : inventory) {
		if (item->getIdCode() == searchIDCode) {
			return item;
		}
	}
	return NULL;
}

/**
 *	Find a Customer using the account ID as a search parameter
 *
 *	@param searchAccountID is a string used as a search parameter
 *	@return pointer to Customer Object with matching account ID
 */
Customer * Store::getMemberFromID(std::string searchAccountID) {
	for (Customer * member : members) {
		if (member->getAccountID() == searchAccountID) {
			return member;
		}
	}
	return NULL;
}

/**
 *	Return a sorted vector
 *
 *	@param searchString1 is a string used to search for matching Product
 *	title or description
 *	@return a sorted vector of strings of ID codes 
 */
std::vector<std::string> Store::productSearch(std::string searchString1) {
	std::string searchString2 = searchString1;
	std::vector<std::string> result;

	if (std::islower(static_cast<char>(searchString1[0]))) {
		searchString2[0] = toupper(searchString2[0]);
	} else {
		searchString2[0] = tolower(searchString2[0]);
	}

	// Search for matching Product title or description
	for (Product * item : inventory) {
		if (item->getTitle().find(searchString1) != std::string::npos ||
			item->getTitle().find(searchString2) != std::string::npos ||
			item->getDescription().find(searchString1) != std::string::npos ||
			item->getDescription().find(searchString2) != std::string::npos) {
			// append ID code if match found
			result.push_back(item->getIdCode());
		}
	}

	// return sorted vector of ID codes
	std::sort(result.begin(), result.end());
	return result;
}

// [DEBUG]: Display's the Store's current inventory
void Store::showInventory() {
	std::cout << "inventory: {" << std::endl;
	for (Product * item : inventory) {
		std::cout << "\tProductObj: { " << &(*item) << std::endl;
		std::cout << "\t\tidCode : " << item->getIdCode() << std::endl;
		std::cout << "\t\ttitle : " << item->getTitle() << std::endl;
		std::cout << "\t\tdescription : " << item->getDescription() << std::endl;
		std::cout << "\t\tprice : " << item->getPrice() << std::endl;
		std::cout << "\t\tquantity available : " << item->getQuantityAvailable() << std::endl;
		std::cout << "\t}" << std::endl;
	}
	std::cout << "};" << std::endl;
}

// [DEBUG]: Display's the Store's current members
void Store::showMembers() {
	std::cout << "members: {" << std::endl;
	for (Customer * member : members) {
		std::cout << "\tCustomerObj: { " << &(*member) << std::endl;
		std::cout << "\t\taccountID : " << member->getAccountID() << std::endl;
		std::cout << "\t\tpremiumMember : " << member->isPremiumMember() << std::endl;
		std::cout << "\t}" << std::endl;
	}
	std::cout << "};" << std::endl;
}