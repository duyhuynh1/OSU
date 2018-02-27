#include "gtest/gtest.h"

// Function prototype
void transformArray(int *&, const int);

// TEST(transformArrayTest, case123) {
// 	int 
// 	EXPECT_TRUE();
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
int main() {
	const int SIZE = 3;
	int *myArray = new int[SIZE];
	myArray[0] = 4;
	myArray[1] = 2;
	myArray[2] = 5;

	std::cout << "myArray original addr: " << myArray << std::endl;
	transformArray(myArray, SIZE);
	std::cout << "myArray updated addr: " << myArray << std::endl;
	for (int i = 0; i < 6; i++) {
		std::cout << myArray[i] << std::endl;
	}

	delete []myArray;
	myArray = NULL;
	return 0;
}