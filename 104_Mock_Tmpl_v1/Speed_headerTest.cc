#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Speed_header.h"// which file it testing added it here
#include "Mock_DriveAlert_client.h" //Corresponding function MOCK

using ::testing::_;
using ::testing::Return;


// Define the test fixture class
class Myclass_TF : public ::testing::Test {
 protected:
 //Declaring Pointers
  speed *sp;
  MockDriveAlertService mockDriveAlertService;
  void SetUp() override {
    // Arrange
    sp = new speed();//intialise the pointer
    ON_CALL(mockDriveAlertService,getLatitude()).WillByDefault(Return(22.77));
    ON_CALL(mockDriveAlertService,getLongitude()).WillByDefault(Return(8.88));
   
  
    std::cout << "Alive" << std::endl;
  }
  void TearDown() override {
    delete sp;
    std::cout << "Dead" << std::endl;
  }
};

TEST_F(Myclass_TF,subtest_HandleSpeedAlert)
{
    EXPECT_CALL(mockDriveAlertService,getLatitude()).Times(1);
    EXPECT_CALL(mockDriveAlertService,getLongitude()).Times(1);

    DriveAlertService::setInstance(&mockDriveAlertService);
    sp->handleSpeedAlert(); //before calling this function setted everything
    // Reset the singleton instance
    DriveAlertService::resetInstance();
}
/*
TEST_F(Myclass_TF, TestStartStop) {
    // Test the start and stop methods
    sp->start();
    EXPECT_TRUE(sp->running());

    sp->stop();
    EXPECT_FALSE(sp->running());
}
*/
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}