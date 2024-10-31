#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <string>

class Event {
public:
    virtual std::string ToString() const = 0;
};
#endif