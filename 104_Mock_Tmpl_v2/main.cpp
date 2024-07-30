/*
main.cpp
*/
#include <iostream>
#include "DriveAlert_client.h"

int main() {
    std::cout << "BundleActivator" << std::endl;
    DriveAlertService& pDriveAlertService = DriveAlertService::getInstance();
    pDriveAlertService.start();

    // Sleep for some time to demonstrate the service running
    std::this_thread::sleep_for(std::chrono::seconds(30));

    // Stop the service before exiting
    pDriveAlertService.stop();

    return 0;
}
