# Assignment 10
You will be writing a (rather primitive) online store simulator.  It will have three classes: Product, Customer and Store.  To make things a little simpler for you, I am supplying you with the three .hpp files. You will write the three implementation files.  You should not alter the provided .hpp files.

You must submit these files: Product.cpp, Customer.cpp, and Store.cpp.  You do not need to submit the .hpp files.

In the main method you use for testing, you should only need to #include Store.hpp.  Remember that your compile command needs to list all of the .cpp files.
## Requirements
- [ ] Implement **Product** Class:
  @brief A Product object represents a product with an ID code, title, description, price and quantity available.
    - [ ] Create a constructor that initializes a Product object taking the following five values: 
      - _idCode_ is a string representing the Product's ID Code
      - _title_ is a string representing the Product's title
      - _description_ is a string representing the Product's description
      - _price_ is a double representing the Product's price
      - _quantityAvailable_ is an integer representing the Product's current available quantity
    - [ ] Create get methods for each member variables
      - _getIdCode()_ - return the Product's ID Code
      - _getTitle()_ - return the Product's title
      - _getDescription()_ - return the Product's description
      - _getPrice()_ - return the Product's price
      - _getPrice()_ - return the Product's current available quantity
    - [ ] Create a method to decrease Product's quantity
      - _decreaseQuantity()_ - decrease's the Product's current quantity by one

- [ ] Implement **Customer** Class:
  @brief A Customer object represents a customer with a name and account ID. Customers must be members of the Store to make a purchase.  Premium members get free shipping.
    - [ ] Create a constructor that initializes a Customer object taking the following three values:
      - _name_ is a string representing the Customer's name
      - _accountID_ is a string representing the Customer's account ID
      - _premiumMember_ is a boolean that indicates if a Customer is a premium member
    - [ ] Create get methods for the Customer object's member variables
      - _getAccountID()_ - return the Customer's account ID
      - _isPremiumMember()_ - return true if the Customer is a premium member, otherwise false
    - [ ] Create a method to add Product objects to the Customer's cart
      - _addProductToCart()_ - add a Product object's ID code to the Customer's cart.
    - [ ] Create a method to empty the Customer's cart
      - _emptyCart()_ clear the Customer's cart 
- [ ] Implement **Store** Class:
  @brief A Store object represents a store, which has some number of products in its inventory and some number of customers as members.
    - [ ] Create a method to add a Product to the inventory
      - _addProduct()_ - add a Product object to the inventory vector
    - [ ] Create a method to add a Customer to the members
      - _addMember()_ - add a Customer object to the members vector
    - [ ] Create a method to return a pointer to a matching Product object's ID Code
      - _getProductFromID()_ - return pointer to product with matching ID.  Returns NULL if no matching ID is found.
        - @param is a string
    - [ ] Create a method to return a pointer to a matching Customer object's account ID
      - _getMemberFromID()_ - return pointer to customer with matching ID.  Returns NULL if no matching ID is found.
    - [ ] Create a method to return a vector of ID codes using title or description as search parameters
      - _productSearch()_ - return a sorted vector of ID codes for every product whose title or description contains the search string. 
        - The first letter of the search string should be case-insensitive, (i.e. a search for "wood" should match Products that have "Wood" in their title or description, and a search for "Wood" should match Products that have "wood" in their title or description.)
        - You may use string::find() and string::npos (Links to an external site.) Links to an external site...
        - You may assume that the search string will consist of a single word.
    - [ ] Create a method to allow members to add products to their cart.
      - _addProductToMemberCart()_ - returns various statements depending on the following conditions:
        - If the product isn't found in the inventory, return "product ID not found". 
        - If the member isn't found in the members, return "member ID not found".
        - If both are found and the product is still available, call the member's addProductToCart method to add the product and then return "product added to cart".
        - If the product was not still available, return "product out of stock". 
        - This function does not need to check how many of that product are available - just that there is at least one.  
        - It should also not change how many are available - that happens during checkout. 
        - The same product can be added multiple times if the customer wants more than one of something.
    - [ ] Create a method to allow a Customer to checkout their cart
      - _checkOutMember()_ - returns various statements depending on the following conditions:
        - If the member ID isn't found, return -1. Otherwise return the charge for the member's cart.
          - **[NOTE]**: This will be the total cost of all the items in the cart, not including any items that are not in the inventory or are out of stock, plus the shipping cost.
        - If a product is not out of stock, you should add its cost to the total and decrease the available quantity of that product by 1. 
          - **[Note]**: That it is possible for an item to go out of stock during checkout. 
          - For example, if the customer has two of the same product in their cart, but the store only has one of that product left, the customer will be able to buy the one that's available, but won't be able to buy a second one, because it's now out of stock.  
        - For **premium members**, the shipping cost is $0.
        - For **normal members**, the shipping cost is 7% of the total cost of the items in the cart. 
        - When the charge for the member's cart has been tabulated, the member's cart should be emptied, and the charge amount returned.
---

