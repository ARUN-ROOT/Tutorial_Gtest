// headertest.cpp
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "header.h"

using namespace std;

// Mock class for the add function
class MockFunction {
 public:
  MOCK_METHOD(int, add, (int a, int b));
};

// Global instance of the MockFunction
MockFunction* mockFunctionInstance = nullptr;

// Mocked add function
int add(int a, int b) {
  if (mockFunctionInstance) {
    return mockFunctionInstance->add(a, b);
  }
  return a + b;  // Default behavior if not mocked
}

// Test fixture
class MyTest : public ::testing::Test {
 protected:
  MockFunction mockFunctionInstance_2;  // Normal instance of MockFunction

  void SetUp() override { mockFunctionInstance = &mockFunctionInstance_2; }

  void TearDown() override { mockFunctionInstance = nullptr; }
};

TEST_F(MyTest, subtest) {
 // EXPECT_CALL(mockFunctionInstance_2, add(2, 3)).WillOnce(::testing::Return(10));
  ON_CALL(mockFunctionInstance_2, add(2, 3))
    .WillByDefault(::testing::Return(10));

  int result = add(2, 3);
  EXPECT_EQ(result, 10);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleMock(&argc, argv);
  return RUN_ALL_TESTS();
}

/*
g++ headertest.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
*/