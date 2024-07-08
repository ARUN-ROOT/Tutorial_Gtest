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
    obj.clientNonVirtualFun(); //it calling both NonVirtual 

    //Method 1:
    header headerObj_main;
    std::cout<<"Calling from main"<<std::endl;
    headerObj_main.headerNonVirtualFun_inside_class();

    std::cout<<"  clientNonVirtualFunSpecial .......in main "<<std::endl;
    obj.clientNonVirtualFunSpecial();

    //client class object . header class pointer then access function in  header. 
    std::cout<<"  clientNonVirtualFunSpecial using two Object .......in main "<<std::endl;
    obj.p->headerNonVirtualFun_inside_classpecial();
    //
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

/*
method1 : in header.h create class and function
          header.h file included in Client.h 
          then main.cpp already client.h included so ...
          class Header create instance in "main.cpp" itself and access function
          

*/