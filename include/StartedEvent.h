#ifndef STARTEDEVENT_H
#define STARTEDEVENT_H
#include <iostream>
#include <memory>
#include <string>
#include "DeviceEvent.h"

class StartedEvent : public  DeviceEvent {
public:
    StartedEvent(std::shared_ptr<Device> d);
    std::string ToString() const override;
};
#endif