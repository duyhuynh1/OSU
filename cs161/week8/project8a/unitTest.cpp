#include "gtest/gtest.h"

// Function prototype
void smallSort2(int *, int *, int *);

TEST(smallSort2Test, case011) {
	int a = 0; int b = 1; int c = 1;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 0 && b == 1 && c == 1);
}

TEST(smallSort2Test, case101) {
	int a = 1; int b = 0; int c = 1;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 0 && b == 1 && c == 1);
}

TEST(smallSort2Test, case110) {
	int a = 1; int b = 1; int c = 0;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 0 && b == 1 && c == 1);
}

TEST(smallSort2Test, case111) {
	int a = 1; int b = 1; int c = 1;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 1 && c == 1);
}

TEST(smallSort2Test, case123) {
	int a = 1; int b = 2; int c = 3;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

TEST(smallSort2Test, case132) {
	int a = 1; int b = 3; int c = 2;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

TEST(smallSort2Test, case213) {
	int a = 2; int b = 1; int c = 3;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

TEST(smallSort2Test, case231) {
	int a = 2; int b = 3; int c = 1;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

TEST(smallSort2Test, case312) {
	int a = 3; int b = 1; int c = 2;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

TEST(smallSort2Test, case321) {
	int a = 3; int b = 2; int c = 1;
	smallSort2(&a, &b, &c);
	EXPECT_TRUE(a == 1 && b == 2 && c == 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}