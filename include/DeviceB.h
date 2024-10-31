#ifndef DEVICEB_H
#define DEVICEB_H
#include <iostream>
#include <string>
#include "Device.h"

class DeviceB : public Device {
public:
    std::string getName() override;
    std::string getDataAsString() override;
};
#endif