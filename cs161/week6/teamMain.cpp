#include "Player.hpp"
#include "gtest/gtest.h"

#include <string>
using std::string;

const Player p1("Tony", 10, 11, 12);
const Player p2("Bob", 1, 1, 1);

TEST(PlayerTest, getNameEquals) {
    EXPECT_EQ("Tony", p1.getName());
}

TEST(PlayerTest, getNameNotEquals) {
    EXPECT_NE("NotTony", p1.getName());
}

TEST(PlayerTest, getPointsEquals) {
    EXPECT_EQ(10, p1.getPoints());
}

TEST(PlayerTest, getPointsNotEquals) {
    EXPECT_NE(0, p1.getPoints());
}

TEST(PlayerTest, getReboundsEquals) {
    EXPECT_EQ(11, p1.getRebounds());
}

TEST(PlayerTest, getAssistsEquals) {
    EXPECT_EQ(p1.getAssists(), 12);
}

TEST(PlayerTest, hasMorePointsThanTrue) {
    EXPECT_TRUE(p1.hasMorePointsThan(p2));
}

TEST(PlayerTest, hasMorePointsThanFalse) {
    EXPECT_FALSE(p2.hasMorePointsThan(p1));
}

/** Execute all unit tests */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
    return 0;
}