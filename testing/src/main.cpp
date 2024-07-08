/***/
/*
#include "header.h"
#include <iostream>

int main() {

  int c = 0;
  // c = add(2, 3);
  std::cout << "Output " << c << std::endl;
  return 0;
}
*/

#include "header.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Mock class for the AddInterface
class MockAdd : public AddInterface {
public:
  MOCK_METHOD(int, add, (int a, int b), (override));
};

// Test fixture
class MyTest : public ::testing::Test {
protected:
  MockAdd mockAdd;

  void SetUp() override {
    // Set up any necessary initializations here
  }

  void TearDown() override {
    // Clean up any necessary resources here
  }
};

TEST_F(MyTest, DefaultBehavior) {
  // Set up default behavior
  ON_CALL(mockAdd, add(::testing::_, ::testing::_))
      .WillByDefault(::testing::Return(0));

  // Test default behavior
  EXPECT_EQ(mockAdd.add(1, 1), 0);
  EXPECT_EQ(mockAdd.add(2, 2), 0);
}

TEST_F(MyTest, SpecificExpectation) {
  // Set up specific expectation
  EXPECT_CALL(mockAdd, add(2, 3)).Times(1).WillOnce(::testing::Return(5));

  // Test specific expectation
  EXPECT_EQ(mockAdd.add(2, 3), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}
