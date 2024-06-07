/**
 *
 *g++ main.cpp -o a.out -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 */
#include <gtest/gtest.h>
#include <iostream>

TEST(testsuit, subtest_1) {
  ASSERT_TRUE(1 == 1);  // condition not comma
}
TEST(testsuit1, subtest_1) { ASSERT_FALSE(1 == 2); }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}