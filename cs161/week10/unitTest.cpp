#include <iostream>
#include "gtest/gtest.h"
#include "Store.hpp"
#include "Product.hpp"
#include "Customer.hpp"

// int main() {
// #include "Product.cpp"
// #include "Customer.cpp"

	// Product myProduct("aaa", "pet rock", "low maintenance pet, fully house-trained", 50, 2);
	// Customer myCustomer("Jenny", "8675309", true);
	// myCustomer.addProductToCart("12345");
	// myCustomer.getCart();

	// Store myStore;
	// myStore.addProduct(&myProduct);
	// myStore.addMember(&myCustomer);
	// myStore.productSearch("Pet");
	// myStore.addProductToMemberCart("aaa", "8675309");
	// myStore.checkOutMember(myCustomer.getAccountID());
	// return 0;
	// ASSERT_TRUE(true);

	// // Product Object test cases
	// Product item1("001aBc", "item1", "item1 test description", 0.99, 2);
	// Product item2("002dEf", "item2", "item2 test description", 1.99, 20);
	// Product item3("123gHi", "item3", "item3 test description", 2.50, 30);
	// Product item4("987JkL", "item4", "item4 test description", 99.99, 0);
	// Customer member1("Tony", "123456789", true);
	// Customer member2("Bob", "987654321", false);

	// std::cout << "Object Addresses: " << std::endl;
	// std::cout << "item1: " << &item1 << std::endl;
	// std::cout << "item2: " << &item2 << std::endl;
	// std::cout << "item3: " << &item3 << std::endl;
	// std::cout << "item4: " << &item4 << std::endl;
	// std::cout << "member1: " << &member1 << std::endl;
	// std::cout << "member2: " << &member2 << std::endl;
	// Store mStoreObj;
	// std::cout << "Generating inventory" << std::endl;
	// mStoreObj.addProduct(&item3);
	// mStoreObj.addProduct(&item1);
	// mStoreObj.addProduct(&item4);
	// mStoreObj.addProduct(&item2);

	// // mStoreObj.showInventory();

	// std::cout << "Querying members from database" << std::endl;
	// mStoreObj.addMember(&member1);
	// mStoreObj.addMember(&member2);
	// // mStoreObj.showMembers();

	// std::cout << "Search for Product using ID Code" << std::endl;
	// // Product * productObjPtr = mStoreObj.getProductFromID("001aBc");
	// // mStoreObj.showInventory();

	// std::cout << "[TEST]: Store::productSearch()" << std::endl;
	// std::vector<std::string> result = mStoreObj.productSearch("test");
	// for (std::string id : result) {
	// 	std::cout << id << " ";
	// }

	// std::cout << "[TEST]: Store::addProductToMemberCart()" << std::endl;
	// mStoreObj.addProductToMemberCart("001aBc", "123456789"); // Qty 2, Price 0.99
	// mStoreObj.addProductToMemberCart("001aBc", "123456789"); // Qty 1, Price 0.99
	// mStoreObj.addProductToMemberCart("001aBc", "123456789"); // Qty 0, don't add
	// mStoreObj.addProductToMemberCart("123gHi", "123456789"); // Qty 30, Price 2.50
	// mStoreObj.addProductToMemberCart("002dEf", "987654321"); // Qty 20, Price 1.99
	// mStoreObj.addProductToMemberCart("123gHi", "987654321"); // Qty 29, Price 2.50
	// mStoreObj.addProductToMemberCart("001aBc", "987654321"); // Qty 0, don't add
	// // mStoreObj.showInventory();
	// std::cout << "[TEST]: Store::checkOutMember()" << std::endl;
	// std::cout << "member 123456789 total: " << mStoreObj.checkOutMember("123456789") << std::endl;
	// std::cout << "member 987654321 total: " << mStoreObj.checkOutMember("987654321") << std::endl;
	// // mStoreObj.showInventory();
// }
// ************************************************************
// Product Object test cases
// ************************************************************
Product item1("001aBc", "item1", "item1 test description", 0.99, 10);
Product item2("002dEf", "item2", "item2 test description", 1.99, 20);

TEST(ProductTest, getIdCode) {
	EXPECT_EQ("001aBc", item1.getIdCode()); 
}

TEST(ProductTest, getTitle) {
	EXPECT_EQ("item1", item1.getTitle());
}

TEST(ProductTest, getDescription) {
	EXPECT_EQ("item1 test description", item1.getDescription());
}

TEST(ProductTest, getPrice) {
	EXPECT_EQ(0.99, item1.getPrice());
}

TEST(ProductTest, getQuantityAvailable) {
	EXPECT_EQ(10, item1.getQuantityAvailable());
}

TEST(ProductTest, decreaseQuantity) {
	item1.decreaseQuantity();
	item1.decreaseQuantity();
	EXPECT_EQ(8, item1.getQuantityAvailable());
}

// ************************************************************
// Customer Object test cases
// ************************************************************
Customer member1("Tony", "123456789", true);
Customer member2("Bob", "987654321", false);

TEST(CustomerTest, getAccountID) {
	EXPECT_EQ("123456789", member1.getAccountID());
}

TEST(CustomerTest, isPremiumMemberTrue) {
	EXPECT_TRUE(member1.isPremiumMember());
}

TEST(CustomerTest, isPremiumMemberFalse) {
	EXPECT_FALSE(member2.isPremiumMember());
}

TEST(CustomerTest, addProductToCart) {
	member1.addProductToCart(item1.getIdCode());
}

TEST(CustomerTest, getCart) {
	std::vector<std::string> member1Cart = member1.getCart();
	std::string verifyItem1 = member1Cart[0];
	EXPECT_EQ("001aBc", verifyItem1);
}

TEST(CustomerTest, emptyCartCheckSize) {
	member1.emptyCart();
	std::vector<std::string> member1Cart = member1.getCart();
	EXPECT_EQ(0, member1Cart.size());
}

// ************************************************************
// Store Object Test Cases
// ************************************************************
TEST(StoreTest, addProductToInventory) { }

TEST(StoreTest, addMemberToMembers) { }

TEST(StoreTest, getProductFromID) { }

TEST(StoreTest, getMemberFromID) { }

TEST(StoreTest, productSearch) { }

TEST(StoreTest, addProductToMemberCart_PRODUCT_NOT_FOUND_ERROR) {
	
}

TEST(StoreTest, addProductToMemberCart_CUSTOMER_NOT_FOUND_ERROR) {

}

TEST(StoreTest, addProductToMemberCart_PRODUCT_OUT_OF_STOCK_ERROR) {

}

TEST(StoreTest, addProductToMemberCart_PRODUCT_ADD_SUCCESS) {
	
}

TEST(Mimir, Test1) {
	Product myProduct("aaa", "pet rock", "low maintenance pet, fully house-trained", 50, 2);
	Customer myCustomer("Jenny", "8675309", true);
	myCustomer.addProductToCart("12345");	// This is where the ERROR is...this IDcode needs to be handled
	myCustomer.getCart();

	Store myStore;
	myStore.addProduct(&myProduct);
	myStore.addMember(&myCustomer);
	myStore.productSearch("Pet");
	myStore.addProductToMemberCart("aaa", "8675309");
	// myStore.showInventory();
	myStore.checkOutMember(myCustomer.getAccountID());
	ASSERT_TRUE(true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}