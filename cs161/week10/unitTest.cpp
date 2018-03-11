#include "gtest/gtest.h"
#include "Product-1.hpp"

// Product Objec test cases
std::string idCode = "001aBc";
std::string title = "item1";
std::string description = "item1 test description";
double price = 0.99;
int quantityAvailable = 10;
Product item1(idCode, title, description, price, quantityAvailable);

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

// 

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}