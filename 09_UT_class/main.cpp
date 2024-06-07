/**
 *  Test_Fixture
 *  Class Added
 *   Two test cases are added
 *   In each Test cases , object is Initialised everytime. we need to avoid this ,for that use TEST_FIXTURE
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

// Define the test fixture class
class Myclass_TF : public ::testing::Test {
 protected:
  Myclass *obj = nullptr;  // Nullptr best Practice
  void SetUp() override {
    // Arrange
    obj = new Myclass("Arun");
    std::cout << "Alive" << std::endl;
  }
  void TearDown() override {
    delete obj;
    std::cout << "Dead" << std::endl;
  }
};

// Test Fixture name should be Present in testsuite name
TEST_F(Myclass_TF, subtest_1) {
  // Act
  std::string str = obj->getName();

  // Assertion
  EXPECT_STREQ(str.c_str(), "Arun");
}

// Test Fixture name should be Present in testsuite name
TEST_F(Myclass_TF, subtest_2) {
  // Act
  std::string str = obj->getName();

  // Assertion
  EXPECT_STREQ(str.c_str(), "Arun");
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}