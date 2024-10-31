#ifndef WORKDONEEVENT_H
#define WORKDONEEVENT_H
#include <iostream>
#include <memory>
#include <string>
#include "DeviceEvent.h"

class WorkDoneEvent : public  DeviceEvent {
public:
    WorkDoneEvent(std::shared_ptr<Device> d);
    std::string ToString() const override;
};
#endif