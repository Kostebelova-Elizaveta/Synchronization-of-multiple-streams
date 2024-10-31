#include "StartedEvent.h"

StartedEvent::StartedEvent(std::shared_ptr<Device> d) : DeviceEvent(d) { };

std::string StartedEvent::ToString() const {
    return "Started " + device->getName();
};