/*********************************************************************
** Author: Tony Huynh
** Date: 03/15/2018
** Description: A Store object represents a store, which has some 
** number of products in its inventory and some number of customers
** as members. The Store class provide methods to add Product objects
** into a member's cart and checkout all item in their cart.
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
		if (item != NULL) {
			if (item->getIdCode() == searchIDCode) {
			return item;
			}	
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
		if (member != NULL) {
			if (member->getAccountID() == searchAccountID) {
			return member;
			}	
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
		if (item != NULL) {
			std::string str = item->getTitle() + " " + item->getDescription();
			if (str.find(searchString1) != std::string::npos ||
				str.find(searchString2) != std::string::npos) {
				// append ID code if a match is found
				result.push_back(item->getIdCode());
			}
		}
	}

	// return sorted vector of ID codes
	std::sort(result.begin(), result.end());
	return result;
}

/**
 *	Allow members to add Products to their cart
 *
 *	@param pID is a string representing the Product's ID code that will be added
 *	@param mID is a string representing the member whose cart the Product
 *	will be added to.
 */      
std::string Store::addProductToMemberCart(std::string pID, std::string mID) {
	const std::string PRODUCT_NOT_FOUND_ERROR = "product ID not found";
	const std::string CUSTOMER_NOT_FOUND_ERROR = "member ID not found";
	const std::string PRODUCT_OUT_OF_STOCK_ERROR = "product out of stock";
	const std::string PRODUCT_ADD_SUCCESS = "product added to cart";

	bool productFoundInInventory = false;
	bool customerFoundInMembers = false;
	bool productIsAvailable = false;
	Product * productObjPtr = getProductFromID(pID);
	Customer * customerObjPtr = getMemberFromID(mID);
	
	// Verify product exist in the inventory
	if (productObjPtr == NULL) {
		return PRODUCT_NOT_FOUND_ERROR;
	}
	productFoundInInventory = true; 
	
	// Verify Product quantity available is greater than 1
	if (productObjPtr->getQuantityAvailable() >= 1) {
		productIsAvailable = true;
	} else {
		return PRODUCT_OUT_OF_STOCK_ERROR;
	}

	// Verify customer exist in the members list
	if (customerObjPtr == NULL) {
		return CUSTOMER_NOT_FOUND_ERROR;
	}
	customerFoundInMembers = true;

	if (productFoundInInventory == customerFoundInMembers && 
		customerFoundInMembers == productIsAvailable) {
		customerObjPtr->addProductToCart(productObjPtr->getIdCode());
	}
	return PRODUCT_ADD_SUCCESS;
}

/**
 *	Allow customers to checkout their cart
 *	
 *	@param mID is a string representing the Customer's account ID
 *	@return the member's total cart monetary value
 */
double Store::checkOutMember(std::string mID) {
	const double NORMAL_MEMBER_SHIPPING_COST = 0.07;	// Normal member shipping rates = 7%
	const double PREMIUM_MEMBER_SHIPPING_COST = 0;		// Premium member shipping rates = 0%
	double itemsTotalCost = 0;
	double totalCost = 0;
	Customer * customerObjPtr = getMemberFromID(mID);
	Product * productObjPtr = NULL;
	std::vector<std::string> checkoutCart;

	// If the member ID isn't found, return -1. Otherwise return the charge for the member's cart.
	if (customerObjPtr == NULL) {
		return -1;
	} else {
		// Get the cart containg Product Obj ID Codes
		checkoutCart = customerObjPtr->getCart();

		for (std::string id : checkoutCart) {
			productObjPtr = getProductFromID(id);
			if (productObjPtr != NULL) {
				if (productObjPtr->getQuantityAvailable() > 0) {
					itemsTotalCost += productObjPtr->getPrice();
					productObjPtr->decreaseQuantity();
				}
			}
		}

		// Apply shipping cost to itemsTotalCost
		if (customerObjPtr->isPremiumMember()) {
			totalCost = itemsTotalCost + PREMIUM_MEMBER_SHIPPING_COST;
		} else {
			totalCost = itemsTotalCost + (itemsTotalCost * NORMAL_MEMBER_SHIPPING_COST);
		}

		customerObjPtr->emptyCart();
		return totalCost;
	}
}

// [DEBUG]: Display's the Store's current inventory
// void Store::showInventory() {
// 	std::cout << "inventory: {" << std::endl;
// 	for (Product * item : inventory) {
// 		std::cout << "\tProductObj: { " << &(*item) << std::endl;
// 		std::cout << "\t\tidCode : " << item->getIdCode() << std::endl;
// 		std::cout << "\t\ttitle : " << item->getTitle() << std::endl;
// 		std::cout << "\t\tdescription : " << item->getDescription() << std::endl;
// 		std::cout << "\t\tprice : " << item->getPrice() << std::endl;
// 		std::cout << "\t\tquantity available : " << item->getQuantityAvailable() << std::endl;
// 		std::cout << "\t}" << std::endl;
// 	}
// 	std::cout << "};" << std::endl;
// }

// [DEBUG]: Display's the Store's current members
// void Store::showMembers() {
// 	std::cout << "members: {" << std::endl;
// 	for (Customer * member : members) {
// 		std::cout << "\tCustomerObj: { " << &(*member) << std::endl;
// 		std::cout << "\t\taccountID : " << member->getAccountID() << std::endl;
// 		std::cout << "\t\tpremiumMember : " << member->isPremiumMember() << std::endl;
// 		std::cout << "\t}" << std::endl;
// 	}
// 	std::cout << "};" << std::endl;
// }