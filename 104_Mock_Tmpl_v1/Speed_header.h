
#ifndef SPEED_HEADER_H
#define SPEED_HEADER_H

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

class speed
{
public:
    speed();
    ~speed();
    void start();
    void stop();
    void run();
    void handleSpeedAlert();
private:
    std::atomic<bool> running;
    std::thread serviceThread;
};

#endif // SPEED_HEADER_H