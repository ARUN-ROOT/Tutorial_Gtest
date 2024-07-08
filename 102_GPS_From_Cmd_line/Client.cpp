/*
Client.cpp
*/
#include "Client.h"
#include <iostream>

Client::Client(GPSInterface *gps): pGPSInterface(gps) {}

void Client::printCoordinates() {
    std::cout << "printCoordinates called" << std::endl;
    double latitude = 0.0, longitude = 0.0;
    std::cout << "Calling getCoordinates" << std::endl;
    pGPSInterface->getCoordinates(latitude, longitude);
    std::cout << "Coordinates received" << std::endl;
    std::cout << "Latitude: " << latitude << " Longitude: " << longitude << std::endl;
}
