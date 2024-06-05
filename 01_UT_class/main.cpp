/**
 *
 * g++ -o test test.cpp $(pkg-config --libs gtest) $(pkg-config --libs gtest_main)
 *
 * ./test
 *
 *
 */

#include <gtest/gtest.h>

int add(int a, int b) { return a + b; }

TEST(addition, positivenumber) { EXPECT_EQ(add(2, 3), 5); }

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}