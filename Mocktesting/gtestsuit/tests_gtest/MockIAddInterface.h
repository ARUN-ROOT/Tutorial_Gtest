#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "header.h"

// Mock class for the AddInterface
class MockAdd : public IAddInterface {
 public:
  MOCK_METHOD(int, add, (int a, int b), (override));
};