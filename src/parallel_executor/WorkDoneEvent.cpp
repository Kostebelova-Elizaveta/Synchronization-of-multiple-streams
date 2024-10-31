#include "WorkDoneEvent.h"

WorkDoneEvent::WorkDoneEvent(std::shared_ptr<Device> d) : DeviceEvent(d) { };

std::string WorkDoneEvent::ToString() const {
    return "Finished " + device->getName();
};