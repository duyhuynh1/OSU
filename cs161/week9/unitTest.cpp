#include "gtest/gtest.h"
#include "T3Reader.hpp"

int main() {
	// Game 1: UNFINISHED
	std::cout << "\n*** STARTING GAME 1 ***" << std::endl;
	std::string filename1 = "data/game1.txt";
	T3Reader game1('x');
	if (game1.readGameFile(filename1)) {
		std::cout << "GAME COMPLETE!" << std::endl;
	} else {
		std::cout << "UNFINISHED GAME" << std::endl;
	}

	// // Game 2: UNFINISHED
	// std::cout << "\n*** STARTING GAME 2 ***" << std::endl;
	// std::string filename2 = "game2.txt";
	// T3Reader game2('o');
	// if (game2.readGameFile(filename2)) {
	// 	std::cout << "GAME COMPLETE!" << std::endl;
	// } else {
	// 	std::cout << "UNFINISHED GAME" << std::endl;
	// }

	// // Game 3: UNFINISHED
	// std::cout << "\n*** STARTING GAME 3 ***" << std::endl;
	// std::string filename3 = "game3.txt";
	// T3Reader game3('x');
	// if (game3.readGameFile(filename3)) {
	// 	std::cout << "GAME COMPLETE!" << std::endl;
	// } else {
	// 	std::cout << "UNFINISHED GAME" << std::endl;
	// }

	// // Game 4: UNFINISHED
	// std::cout << "\n*** STARTING GAME 4 ***" << std::endl;
	// std::string filename4 = "game4.txt";
	// T3Reader game4('o');
	// if (game4.readGameFile(filename4)) {
	// 	std::cout << "GAME COMPLETE!" << std::endl;
	// } else {
	// 	std::cout << "UNFINISHED GAME" << std::endl;
	// }

	// // Game 5: X_WON
	// std::cout << "\n*** STARTING GAME 5 ***" << std::endl;
	// std::string filename5 = "game5.txt";
	// T3Reader game5('x');
	// if (game5.readGameFile(filename5)) {
	// 	std::cout << "GAME COMPLETE!" << std::endl;
	// } else {
	// 	std::cout << "UNFINISHED GAME" << std::endl;
	// }
}
// Function prototype
// void transformArray(int * &, const int);

// TEST(transformArrayTest, caseAllNegatives) {
// 	const int SIZE = 2;
// 	int *mArray = new int[SIZE];
// 	mArray[0] = -1;
// 	mArray[1] = -4;
// 	transformArray(mArray, SIZE);
// 	EXPECT_TRUE(mArray[0] == -1 && mArray[2] == 0 && 
// 				mArray[1] == -4 && mArray[3] == -3);
// 	delete [] mArray;
// 	mArray = NULL;
// }

// TEST(transformArrayTest, case425) {
// 	const int SIZE = 3;
// 	int *mArray = new int[SIZE];
// 	mArray[0] = 4;
// 	mArray[1] = 2;
// 	mArray[2] = 5;
// 	transformArray(mArray, SIZE);
// 	EXPECT_TRUE(mArray[3] == 5 && mArray[4] == 3 && mArray[5] == 6);
// 	delete [] mArray;
// 	mArray = NULL;
// }

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }