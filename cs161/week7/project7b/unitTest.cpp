#include "Person.hpp"
#include "gtest/gtest.h"

// Function prototype
double stdDev(Person [], int);

TEST(TestPerson, getNameTrue) {
	Person p1("Tony", 25);
	Person p2("Billy", 27);
	EXPECT_TRUE("Tony" == p1.getName() &&
				"Tony" != p2.getName());
}

TEST(TestPerson, getAgeEqual) {
	Person p1("Tony", 25);
	Person p2("Billy", 27);
	EXPECT_EQ(25, p1.getAge());
	EXPECT_NE(25, p2.getAge());
}

TEST(TestStdDev, onePersonGroupCalc) {
	const int SIZE = 1;
	Person group[] = { Person("p1", 20)};
	EXPECT_EQ(0, stdDev(group, SIZE));
}

TEST(TestStdDev, twoPersonGroupCalc) {
	const int SIZE = 2;
	Person group[] = { Person("p1", 20),
                       Person("p2", 20) };
    EXPECT_TRUE(stdDev(group, SIZE) == 0);
}

TEST(TestStdDev, multiPersonGroupCalc) {
	const int SIZE = 6;
	Person group[] = { Person("p1", 15),
                       Person("p2", 10),
                       Person("p3", 25),
                       Person("p4", 22),
                       Person("p5", 23),
                       Person("p6", 15) };
    EXPECT_TRUE(stdDev(group, SIZE) - 5.3437398 <= 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}