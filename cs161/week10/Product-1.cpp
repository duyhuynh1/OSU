/*********************************************************************
** Author: Tony Huynh
** Date: 03/14/2018
** Description: Create a Product object
*********************************************************************/
#include "Product-1.hpp"

/**
 *	Constructor that initializes a Product object taking the following five values:
 *
 *	@param idCode is a string representing the Product's ID Code
 *	@param title is a string representing the Product's title
 *	@param description is a string representing the Product's description
 *	@param price is a double representing the Product's price
 *	@param quantityAvailable is an integer representing the Product's current available quantity
 */
Product::Product(std::string id, std::string t, std::string d,
				 double p, int qa) {
	idCode = id;
	title = t;
	description = d;
	price = p;
	quantityAvailable = qa;
}

/**
 *	Return the Product's ID Code
 */
std::string Product::getIdCode() { return idCode; }

/**
 *	Return the Product's title
 */
std::string Product::getTitle() { return title; }

/**
 *	Return the Product's description
 */
std::string Product::getDescription() { return description; }

/**
 *	Return the Product's price
 */
double Product::getPrice() { return price; }

/**
 *	Return the Product's current available quantity
 */
int Product::getQuantityAvailable() { return quantityAvailable; }


/**
 *	Decrease the Product's current available quantity by one
 */
void Product::decreaseQuantity() {
	quantityAvailable -= 1;
}