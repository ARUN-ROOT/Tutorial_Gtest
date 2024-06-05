/**
 *
 *g++ main.cpp -o GTestExample -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/02_UT_class/
 *-I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/02_UT_class/
 *
 */

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }

TEST(addition, positivenumber) { EXPECT_EQ(add(2, 5), 7); }

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
