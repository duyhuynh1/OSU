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
		std::string str = item->getTitle() + " " + item->getDescription();
		std::cout << str << std::endl;
		if (str.find(searchString1) != std::string::npos ||
			str.find(searchString2) != std::string::npos) {
			// append ID code if match found
			result.push_back(item->getIdCode());
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
	std::cout << "productObjPtr: " << productObjPtr << std::endl;	// REMOVE
	Customer * customerObjPtr = getMemberFromID(mID);
	std::cout << "customerObjPtr: " << customerObjPtr << std::endl;	// REMOVE

	// Verify product exist in the inventory
	if (productObjPtr == NULL) {
		std::cout << PRODUCT_NOT_FOUND_ERROR << std::endl;	// REMOVE
		return PRODUCT_NOT_FOUND_ERROR;
	}
	std::cout << "Store::addProductToMemberCart() - product ID found" << std::endl;	// REMOVE
	productFoundInInventory = true; 
	
	// Verify customer exist in the members list
	if (customerObjPtr == NULL) {
		std::cout << CUSTOMER_NOT_FOUND_ERROR << std::endl;	// REMOVE
		return CUSTOMER_NOT_FOUND_ERROR;
	}
	std::cout << "Store::addProductToMemberCart() - member ID found" << std::endl; // REMOVE
	customerFoundInMembers = true;

	// Verify Product quantity available is greater than 1
	if (productObjPtr->getQuantityAvailable() >= 1) {
		std::cout << "quantity available!" << std::endl;	// REMOVE
		productIsAvailable = true;
	} else {
		std::cout << PRODUCT_OUT_OF_STOCK_ERROR << std::endl;	// REMOVE
		return PRODUCT_OUT_OF_STOCK_ERROR;
	}

	std::cout << "productFoundInInventory: " << productFoundInInventory << std::endl;	// REMOVE
	std::cout << "customerFoundInMembers: " << customerFoundInMembers << std::endl;	// REMOVE
	std::cout << "productIsAvailable: " << productIsAvailable << std::endl;	// REMOVE
	if (productFoundInInventory == customerFoundInMembers && 
		customerFoundInMembers == productIsAvailable) {
		std::cout << PRODUCT_ADD_SUCCESS << std::endl;	// REMOVE
		customerObjPtr->addProductToCart(productObjPtr->getIdCode());
		return PRODUCT_ADD_SUCCESS;
	}
}

/**
 *	Allow customers to checkout their cart
 *	
 *	@param mID is a string 
 *	@return the 
 */
// - _checkOutMember()_ - returns various statements depending on the following conditions:
//   - **[NOTE]**: This will be the total cost of all the items in the cart, not including any items that are not in the inventory or are out of stock, plus the shipping cost.
// - If a product is not out of stock, you should add its cost to the total and decrease the available quantity of that product by 1. 
//   - **[Note]**: That it is possible for an item to go out of stock during checkout. 
//   - For example, if the customer has two of the same product in their cart, but the store only has one of that product left, the customer will be able to buy the one that's available, but won't be able to buy a second one, because it's now out of stock.  
// - For **premium members**, the shipping cost is $0.
// - For **normal members**, the shipping cost is 7% of the total cost of the items in the cart. 
// - When the charge for the member's cart has been tabulated, the member's cart should be emptied, and the charge amount returned.
double Store::checkOutMember(std::string mID) {
	const double NORMAL_MEMBER_SHIPPING_COST = 0.07;	// 7% of Total Cost
	const double PREMIUM_MEMBER_SHIPPING_COST = 0;
	double itemsTotalCost = 0;
	double totalCost = 0;
	Customer * customerObjPtr = getMemberFromID(mID);
	std::cout << "customerObjPtr: " << customerObjPtr << std::endl;	// REMOVE
	std::vector<std::string> checkoutCart;

	// If the member ID isn't found, return -1. Otherwise return the charge for the member's cart.
	if (customerObjPtr == NULL) {
		return -1;
	} else {
		std::cout << "member found" << std::endl;	// REMOVE
		std::cout << "calculating total:..." << std::endl;	// REMOVE
		// Get the cart. Cart contains Product Obj ID Codes
		checkoutCart = customerObjPtr->getCart();

		// For each item in the cart check if qty available.
		// If qty = 0; then skip adding to total and subtracting qty
		for (std::string id : checkoutCart) {
			if (getProductFromID(id)->getQuantityAvailable() > 0) {
				std::cout << "product is still available" << std::endl;	// REMOVE
				itemsTotalCost += getProductFromID(id)->getPrice();
				getProductFromID(id)->decreaseQuantity();
			}
		}

		// Apply shipping cost to itemsTotalCost
		std::cout << "applying shipping rates" << std::endl;
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