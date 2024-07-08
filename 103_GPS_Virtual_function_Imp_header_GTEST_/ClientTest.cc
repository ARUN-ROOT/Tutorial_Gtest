/*
ClientTest.cc
*/
#include "Mock_IGPS.h" //Mocking header file
#include "Client.h"//which file should be tested

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::Return;
using ::testing::SetArgReferee;
using ::testing::DoAll;


//Don't use this test Case .its not use when directly caled getCoordinates
TEST(testsuit, subtest_printCoordinates_1) {
    std::cout << "Test started" << std::endl;
    MockGPS pMockGPS;
    double lat, longi;
    pMockGPS.getCoordinates(lat, longi); // Direct call for testing
    std::cout << "Direct call test" << std::endl;
     std::cout << "Latitude: " << lat<< " Longitude: " << longi << std::endl;

}

//This one Important , actually You are calling PrintCoordinates function which need getCoordinate we mocked this function
TEST(testsuit, subtest_printCoordinates_2) {  
    std::cout << "Test started" << std::endl;
    MockGPS pMockGPS;
    Client obj(&pMockGPS); // passing address
 /*  EXPECT_CALL(pMockGPS, getCoordinates(::testing::_, ::testing::_))
        .Times(1)
        .WillOnce(DoAll(SetArgReferee<0>(37.7749), SetArgReferee<1>(-122.4194)));*/

     ON_CALL(pMockGPS, getCoordinates(::testing::_, ::testing::_))
        .WillByDefault(DoAll(SetArgReferee<0>(37.7749), SetArgReferee<1>(-122.4194)));

    std::cout << "Before printCoordinates" << std::endl;
    obj.printCoordinates();
    std::cout << "After printCoordinates" << std::endl;
}

TEST(testsuit, subtest_ClientNonVirtualFun) {  
    std::cout << "Test started" << std::endl;
    MockGPS pMockGPS;
    Client obj(&pMockGPS); // passing address
    std::cout << "Before clientNonVirtual" << std::endl;
    int result = obj.clientNonVirtualFun();
    std::cout << "After clientNonVirtual" << std::endl;
    EXPECT_EQ(1,result);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
