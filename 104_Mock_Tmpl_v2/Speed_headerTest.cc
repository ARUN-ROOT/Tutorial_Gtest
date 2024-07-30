#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Speed_header.h"

using ::testing::_;
using ::testing::Return;



// Define the test fixture class
class Myclass_TF : public ::testing::Test {
  protected:
  speed obj;
 
  void SetUp() override {
  
  }
  void TearDown() override {
     }
};

TEST_F(Myclass_TF,subtest_display)
{
    obj.display();
    EXPECT_EQ(obj.disp,1);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}