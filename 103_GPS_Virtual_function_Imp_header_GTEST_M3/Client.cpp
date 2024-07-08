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


 int Client::clientNonVirtualFun()
 {
    headerNonVirtualFun(); //global
    header headerObj_client; //Method 2 :important i cannot create header headerObj_client object in Client.h file .
                                // directly i create object here in Client.cpp file 
    std::cout<<"*****"<<std::endl;
    headerObj_client.headerNonVirtualFun_inside_class(); //inside class
    return 1;
 }

  int Client::clientNonVirtualFunSpecial()
  {
     std::cout<<"**  clientNonVirtualFunSpecial ***"<<std::endl; 
     p->headerNonVirtualFun_inside_classpecial();//Method3 pointer object is created in client.h 
     return 1;
  }