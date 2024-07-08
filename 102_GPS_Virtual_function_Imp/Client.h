/*
Client.h
*/
#include "IGPS.h"


class Client
{
    public:
    //Client(GPSInterface *gps): pGPSInterface(gps) {}
    Client(GPSInterface *gps);
    void printCoordinates();
     
    private:
    GPSInterface *pGPSInterface;
};