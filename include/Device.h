#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
#include <string>

class Device {
public:
    virtual std::string getName() = 0;
    virtual std::string getDataAsString() = 0;
};
#endif