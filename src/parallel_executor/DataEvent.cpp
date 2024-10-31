#include "DataEvent.h"

DataEvent::DataEvent(std::shared_ptr<Device> d) : DeviceEvent(d) { };

std::string DataEvent::ToString() const {
    return device->getDataAsString() + " from " + device->getName();
};