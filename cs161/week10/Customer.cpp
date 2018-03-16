/*********************************************************************
** Author: Tony Huynh
** Date: 03/15/2018
** Description: Create a Customer object that represents a customer 
** with a name and account ID. Customers must be members of the 
** Store to make a purchase. Premium members get free shipping.
*********************************************************************/
#include "Customer.hpp"

/**
 *	@param n is a string representing the Customer's name
 *	@param a is a string representing the Customer's account ID
 *	@param pm is a boolean indicating if the Customer has a premium
 *	membership.
 */
Customer::Customer(std::string n, std::string a, bool pm) {
	name = n;
	accountID = a;
	premiumMember = pm;
}

/**
 *	Return the Customer's account ID
 */
std::string Customer::getAccountID() { return accountID; }

/**
 *	Return the Customer's cart
 */
std::vector<std::string> Customer::getCart() { return cart; }

/**
 *	Add Product objects to the Customer's cart
 *	
 *	@param item is a string representing the Product's ID code
 */
void Customer::addProductToCart(std::string item) { cart.push_back(item); }

/**
 *	Indicates whether the Customer is a premium member
 *
 *	@return true if the Customer is a premium member, otherwise false
 */
bool Customer::isPremiumMember() { return premiumMember; }

/**
 *	Empty the Customer's cart
 */
void Customer::emptyCart() { cart.clear(); }