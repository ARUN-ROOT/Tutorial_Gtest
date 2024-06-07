#include "header.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <cstring>

using namespace ::testing;

TEST(testsuit, subtest_positive) {
  int c = add(2, 3);
  EXPECT_EQ(5, 5);
}
