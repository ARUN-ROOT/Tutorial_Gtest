

//Method 1: Include DriveAlert_client header file

#include "DriveAlert_client.h"

#include "Speed_header.h"

speed::speed():running(false){}
speed::~speed()
{
    stop();
}

void speed::run() {

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        handleSpeedAlert();     
       
    }
}


void speed::start() {
    if (!running) {
        running = true;
        serviceThread = std::thread(&speed::run, this);
    }
}

void speed::stop() {
    if (running) {
        running = false;
        if (serviceThread.joinable()) {
            serviceThread.join();
        }
    }
}

void speed::display() {
    std::cout<<"Display Speed"<<std::endl;
    disp = 1;
}

void speed::handleSpeedAlert()
{
    std::cout << "[speed] : handleSpeedAlert" << std::endl;
    DriveAlertService &theApp = DriveAlertService::getInstance();
    double latitude = theApp.getLatitude();
    double longitude = theApp.getLongitude();
    std::cout << "[speed] : Latitude = " << latitude << ", Longitude = " << longitude << std::endl;

}

/*

//Method 2: without Include DriveAlert_client header file
//use forward declaration of DriveAlertservice class

class DriveAlertService;
#include "Speed_header.h"

speed::speed():running(false){}
speed::~speed()
{
    stop();
}

void speed::run() {

    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        handleSpeedAlert();     
       
    }
}


void speed::start() {
    if (!running) {
        running = true;
        serviceThread = std::thread(&speed::run, this);
    }
}

void speed::stop() {
    if (running) {
        running = false;
        if (serviceThread.joinable()) {
            serviceThread.join();
        }
    }
}

void speed::handleSpeedAlert()
{
    std::cout << "[speed] : handleSpeedAlert" << std::endl;
    DriveAlertService &theApp = DriveAlertService::getInstance();
    double latitude = theApp.getLatitude();
    double longitude = theApp.getLongitude();
    std::cout << "[speed] : Latitude = " << latitude << ", Longitude = " << longitude << std::endl;
}



*/