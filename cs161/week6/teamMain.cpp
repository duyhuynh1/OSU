#include "Player.hpp"
#include "Team.hpp"
#include "gtest/gtest.h"

const Player p1("Charlotte", 24, 10, 7);
const Player p2("Emily", 21, 13, 9);
const Player p3("Anne", 20, 10, 8);
const Player p4("Jane", 19, 10, 10);
const Player p5("Mary", 18, 11, 8);
const Team team1(p1, p2, p3, p4, p5);

TEST(TeamTest, TotalPointsEquals) {
    EXPECT_EQ(102, team1.totalPoints());
}

TEST(TeamTest, PlayerStatPointsEquals) {
    Player t1p1 = team1.getPointGuard();
    int actualPoints = t1p1.getPoints();
    int actualRebounds = t1p1.getRebounds();
    int actualAssists = t1p1.getAssists();
    EXPECT_EQ(24, actualPoints);
    EXPECT_EQ(10, actualRebounds);
    EXPECT_EQ(7, actualAssists);
}

TEST(PlayerTest, P2HasMorePointsThanP1True) {
    Player t1p1 = team1.getPointGuard();
    Player t1p2 = team1.getShootingGuard();
    EXPECT_TRUE(t1p1.hasMorePointsThan(t1p2));
}

TEST(PlayerTest, PlayerNameTrue) {
    Player t1p1 = team1.getPointGuard();
    EXPECT_EQ("Charlotte", t1p1.getName());
}

/** Execute all unit tests */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}