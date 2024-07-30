#ifndef DRIVEALERT_CLIENT_H
#define DRIVEALERT_CLIENT_H

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

#include "Speed_header.h"


class DriveAlertService {
private:
    double m_longitude;
    double m_latitude;
    std::atomic<bool> running;
    std::thread serviceThread;

    DriveAlertService();
    virtual ~DriveAlertService();

    void run();

public:
    void start();
    void stop();
    static DriveAlertService& getInstance();
    double getLatitude();
    double getLongitude();
    void setLatitude(double latitude);
    void setLongitude(double longitude);
    
    static speed objSpeed;

};

#endif // DRIVEALERT_CLIENT_H
