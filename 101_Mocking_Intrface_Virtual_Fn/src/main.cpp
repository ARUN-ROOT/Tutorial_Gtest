/***/
/*
#include <iostream>
#include "header.h"

int main() {
  Add obj;
  int c = 0;
  c = obj.add(2, 3);
  std::cout << "Output " << c << std::endl;
  return 0;
}
*/

/**
 * Interface used in header.h
 * Interface function only doing Gtest
 * Here we commented main.cpp int main above
 * Here we are Mocking the Interface virtual function.Doing Test cases
 * ...instead of gtestsuit.
 *
 *
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "header.h"

// Mock class for the AddInterface
class MockAdd : public IAddInterface {
 public:
  MOCK_METHOD(int, add, (int a, int b), (override));
};

// Test fixture
class MyTest : public ::testing::Test {
 protected:
  // Create Object
  MockAdd mockAdd;

  void SetUp() override {
    // Set up any necessary initializations here
  }

  void TearDown() override {
    // Clean up any necessary resources here
  }
};

TEST_F(MyTest, DefaultBehavior_1) {
  // Set up default behavior
  // In below line always Return 0 when this function is called whatever arguments takes ...
  // So return value is 0 and EXPECT EQ value is 0.
  ON_CALL(mockAdd, add(::testing::_, ::testing::_)).WillByDefault(::testing::Return(0));

  // Test default behavior
  // Below this function called it will go above line always return 0 only whatever the Argument it takes
  EXPECT_EQ(mockAdd.add(1, 1), 0);
  EXPECT_EQ(mockAdd.add(2, 2), 0);
}

TEST_F(MyTest, DefaultBehavior_2) {
  // Set up default behavior
  // In below line always Return 0 when this function is called whatever arguments takes ...
  ON_CALL(mockAdd, add(::testing::_, ::testing::_)).WillByDefault(::testing::Return(5));

  // Test default behavior
  // Below this function called it will go above line
  EXPECT_EQ(mockAdd.add(1, 1), 5);
}

// this testcase is fail return 6 only...
TEST_F(MyTest, SpecificExpectation) {
  // Set up specific expectation
  EXPECT_CALL(mockAdd, add(2, 3)).Times(1).WillOnce(::testing::Return(6));

  // Test specific expectation
  EXPECT_EQ(mockAdd.add(2, 3), 6);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
