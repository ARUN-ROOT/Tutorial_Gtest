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


class IGPS_ConcreteClassImplementation : public GPSInterface {
public:
    void getCoordinates(double &lat, double &longi) override;
};
#endif