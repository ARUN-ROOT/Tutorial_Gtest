/*
IGPS.h
*/

#ifndef IGPS_H
#define IGPS_H

class GPSInterface
{
    public:
    virtual ~GPSInterface()=default;
    virtual void getCoordinates(double &lat,double &longi)=0;

};

#endif


/*Note:
IGPS.cpp
Since GPSInterface only contains pure virtual functions,
it doesn't need an implementation file. However, we can implement a simple client class that uses the GPSInterface.
*/
