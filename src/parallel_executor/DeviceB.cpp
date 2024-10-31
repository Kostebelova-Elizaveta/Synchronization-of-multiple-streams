#include "DeviceB.h"

std::string DeviceB::getName() {
    return "B";
};

std::string DeviceB::getDataAsString() {
    std::string text;
    for (int i=0; i<3; i++)
        text += std::to_string(0 + rand() % 198) + " ";
    return text;
};