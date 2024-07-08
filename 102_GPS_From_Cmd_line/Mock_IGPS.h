/*
Mock_IGPS.h
*/
#ifndef MOCK_IGPS_H
#define MOCK_IGPS_H

#include <gmock/gmock.h>
#include "IGPS.h"

class MockGPS : public GPSInterface {
public:
    MOCK_METHOD(void, getCoordinates, (double &lat, double &longi), (override));
};

#endif // MOCK_IGPS_H
