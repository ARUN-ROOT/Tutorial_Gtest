/**
 *   Class Added
 *
 *g++ main.cpp -o a.out -lgtest -lgtest_main -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
 */
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

class Myclass {
 private:
  string name;

 public:
  Myclass(string _name) : name(_name) {}
  std::string getName() { return name; }
};

TEST(testsuit, subtest_1) {
  // Arrange
  Myclass obj("Arun");

  // Act
  std::string str = obj.getName();

  // Assertion
  EXPECT_STREQ(str.c_str(), "Arun");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}