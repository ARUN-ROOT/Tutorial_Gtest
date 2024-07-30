#include "DriveAlert_client.h"

#include "IGPS.h" //Not added in DriveAlert_client.h directly added here DriveAlert_client.cpp

speed DriveAlertService::objSpeed;  // Define the static member important


DriveAlertService::DriveAlertService() : m_longitude(0.0), m_latitude(0.0), running(false) {}

DriveAlertService::~DriveAlertService() {
    stop(); // Ensure the service is stopped when the object is destroyed
}

DriveAlertService& DriveAlertService::getInstance() {
    static DriveAlertService sInstance;
    return sInstance;
}

void DriveAlertService::run() {
    IGPS_ConcreteClassImplementation objIGPS;
    std::cout<<"*****"<<std::endl;

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        double lat=0.0,longi=0.0;
        objIGPS.getCoordinates(lat,longi);

        setLatitude(lat);
        setLongitude(longi);
        std::cout << "[DALT]:Latitude set to: " << getLatitude() << std::endl;
        std::cout << "[DALT]:Longitude set to: " << getLongitude() << std::endl;
    }
}

void DriveAlertService::start() {
    if (!running) {
        running = true;
        objSpeed.start();
        serviceThread = std::thread(&DriveAlertService::run, this);
    }
}

void DriveAlertService::stop() {
    if (running) {
        running = false;
        if (serviceThread.joinable()) {
            serviceThread.join();
        }
    }
}

double DriveAlertService::getLatitude() {
    return m_latitude;
}

double DriveAlertService::getLongitude() {
    return m_longitude;
}

void DriveAlertService::setLatitude(double latitude) {
    m_latitude = latitude;
}

void DriveAlertService::setLongitude(double longitude) {
    m_longitude = longitude;
}
