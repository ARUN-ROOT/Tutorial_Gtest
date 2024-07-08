/*
main.cpp
*/
#include <iostream>
#include "Client.h"
#include "IGPS.h"

int main()
{
    IGPS_ConcreteClassImplementation gpsImp;
    Client obj(&gpsImp);
    obj.printCoordinates();
    std::cout<<"======"<<std::endl;
    obj.clientNonVirtualFun();
    return 0;
}

/*
Output:
 g++ -o main main.cpp Client.cpp IGPS.cpp header.cpp
 ./main 
printCoordinates called
Calling getCoordinates
Coordinates received
Latitude: 22.71 Longitude: 8.854
*/

/*
g++ ClientTest.cc Client.cpp header.cpp -o a.out -lgtest -lgtest_main -lgmock -pthread -L/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/ -I/home/t0101u7/05_UnitTest_Tutorial/Tutorial_Gtest/library/
*/