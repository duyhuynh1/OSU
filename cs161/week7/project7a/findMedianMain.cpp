/*********************************************************************
** Author: Tony Huynh
** Date: 2/21/2018
** Description: findMedian.cpp Unit Test
*********************************************************************/
#include <gtest/gtest.h>

// Function prototype
double findMedian(int array[], int size);

TEST(findMedianTest, oddArrayOneNumber) {
	int oddArrayOneNumber[] = { 7 };
	const int SIZE = sizeof(oddArrayOneNumber) / sizeof(oddArrayOneNumber[0]);
	EXPECT_EQ(7, findMedian(oddArrayOneNumber, SIZE));
	EXPECT_NE(8, findMedian(oddArrayOneNumber, SIZE));
}

TEST(findMedianTest, evenArrayTwoNumber) {
	int evenArrayTwoNumber[] = { 2, 5 };
	const int SIZE = sizeof(evenArrayTwoNumber) / sizeof(evenArrayTwoNumber[0]);
	EXPECT_EQ(3.5, findMedian(evenArrayTwoNumber, SIZE));
	EXPECT_NE(3.0, findMedian(evenArrayTwoNumber, SIZE));
}

TEST(findMedianTest, oddArrayAnySize) {
	int oddArray[] = { 9, -13, 9, 11, 9, 13, -11, 9, 0, 8, 11 };
	const int SIZE = sizeof(oddArray) / sizeof(oddArray[0]);
	EXPECT_EQ(9, findMedian(oddArray, SIZE));
	EXPECT_NE(2, findMedian(oddArray, SIZE));
}

TEST(findMedianTest, evenArrayAnySize) {
	int evenArray[] = { 5, 11, 12, 4, 8, 21 };
	const int SIZE = sizeof(evenArray) / sizeof(evenArray[0]);
	EXPECT_EQ(9.5, findMedian(evenArray, SIZE));
	EXPECT_NE(2.0, findMedian(evenArray, SIZE));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}