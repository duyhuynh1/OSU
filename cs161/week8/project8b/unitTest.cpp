#include "gtest/gtest.h"

// Function prototype
void transformArray(int * &, const int);

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
	myArray[0] = 1;
	myArray[1] = 2;
	myArray[2] = 3;

	transformArray(myArray, SIZE);
	std::cout << "myArray[]: { ";
	for (int i = 0; i < 6; i++) {
		std::cout << myArray[i] << " ";
	}
	std::cout << "};" << std::endl;
	delete [] myArray;
	myArray = NULL;
	return 0;
}