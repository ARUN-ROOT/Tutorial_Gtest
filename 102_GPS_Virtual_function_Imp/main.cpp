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
    return 0;
}

/*
Output:
 g++ -o main main.cpp Client.cpp IGPS.cpp
 ./main 
printCoordinates called
Calling getCoordinates
Coordinates received
Latitude: 22.71 Longitude: 8.854
*/
