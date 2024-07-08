/*
Client.h
*/
#include "IGPS.h" //Interface Pure Virtual fun
#include "header.h"//function in Globally


class Client
{
    public:
    //Client(GPSInterface *gps): pGPSInterface(gps) {}
    Client(GPSInterface *gps);
    void printCoordinates();
    int clientNonVirtualFun(); // header.h file Non virtual fun is used inside this function
    
     header *p; //special function access using this pointer
     int clientNonVirtualFunSpecial();
    private:
    GPSInterface *pGPSInterface;
};