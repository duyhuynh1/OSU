#include "gtest/gtest.h"

// Function prototype
void transformArray(int * &, const int);

TEST(transformArrayTest, caseAllNegatives) {
	const int SIZE = 2;
	int *mArray = new int[SIZE];
	mArray[0] = -1;
	mArray[1] = -4;
	transformArray(mArray, SIZE);
	EXPECT_TRUE(mArray[0] == -1 && mArray[2] == 0 && 
				mArray[1] == -4 && mArray[3] == -3);
	delete [] mArray;
	mArray = NULL;
}

TEST(transformArrayTest, case425) {
	const int SIZE = 3;
	int *mArray = new int[SIZE];
	mArray[0] = 4;
	mArray[1] = 2;
	mArray[2] = 5;
	transformArray(mArray, SIZE);
	EXPECT_TRUE(mArray[3] == 5 && mArray[4] == 3 && mArray[5] == 6);
	delete [] mArray;
	mArray = NULL;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}