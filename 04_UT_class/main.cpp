/**
 *
 *g++ main.cpp -o a.out -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 */
#include <gtest/gtest.h>
#include <iostream>

TEST(testsuit, subtest_1) {
  ASSERT_EQ(1, 1);  // Put in , comma in between
  // FATAL FAILURE Not executed nxt line , Here Tue ASSERT is So Nxt Line Executed
  //
  std::cout << "NextLine Executed" << std::endl;
}
TEST(testsuit1, subtest_1) {
  ASSERT_EQ(1, 2);
  std::cout << "NextLine Executed" << std::endl;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}