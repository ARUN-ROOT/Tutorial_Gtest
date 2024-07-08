#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "MockIAddInterface.h"

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
  // Below this function called it will go above line
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
