#ifndef DEVICEEVENT_H
#define DEVICEEVENT_H
#include <iostream>
#include <memory>
#include <string>
#include "Event.h"
#include "Device.h"

class DeviceEvent : public Event {
protected:
    std::shared_ptr<Device> device;
public:
    DeviceEvent(std::shared_ptr<Device> d);
    virtual std::string ToString() const = 0;
};
#endif