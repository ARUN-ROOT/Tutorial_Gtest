/**
 *
 *g++ main.cpp -o a.out -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 */
#include <gtest/gtest.h>
#include <iostream>

TEST(testsuit, subtest_1) {
  // Arrange (Arrangre Everything required to run the test)
  int a = 5;
  int b = 3;

  // Act
  int c = a + b;

  // Assertion(Verify the output)
  EXPECT_EQ(c, 8);
  std::cout << "NextLine Executed" << std::endl;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}