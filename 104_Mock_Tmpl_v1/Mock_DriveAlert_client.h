#ifndef MOCK_DRIVEALERT_CLIENT_H
#define MOCK_DRIVEALERT_CLIENT_H

#include <gmock/gmock.h> //for Gmock
//#include "DriveAlert_client.h" -->
#include "Mock_DriveAlert_client_mirror.h"

class MockDriveAlertService:public DriveAlertService //from mirror it is inherting DriveAlertService
{
    public:
    MOCK_METHOD(double,getLatitude,(),(override));
    MOCK_METHOD(double,getLongitude,(),(override));
};

#endif //MOCK_DRIVEALERT_CLIENT_H
