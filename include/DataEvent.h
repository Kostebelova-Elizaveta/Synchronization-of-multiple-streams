#ifndef DATAEVENT_H
#define DATAEVENT_H
#include <iostream>
#include <memory>
#include <string>
#include "DeviceEvent.h"

class DataEvent : public  DeviceEvent {
public:
    DataEvent(std::shared_ptr<Device> d);
    std::string ToString() const override;
};
#endif