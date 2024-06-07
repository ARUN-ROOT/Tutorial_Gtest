/**
 *
 *g++ main.cpp -o a.out -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 */
#include <gtest/gtest.h>
#include <iostream>

TEST(testsuit, subtest_1) {
  EXPECT_EQ(1, 1);  // Put in , comma in between
  std::cout << "NextLine Executed" << std::endl;
}
TEST(testsuit1, subtest_1) {
  EXPECT_EQ(1, 2);
  std::cout << "NextLine Executed" << std::endl;
  // even its failure Nxt line executed
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}