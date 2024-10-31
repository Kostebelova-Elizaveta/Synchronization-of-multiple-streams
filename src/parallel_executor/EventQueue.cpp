#include "EventQueue.h"


void EventQueue::push(const std::shared_ptr<const Event>& event) {
    std::unique_lock<std::mutex> lock(mtx);
    queue.push(event);
    cv.notify_one();
};

std::shared_ptr<const Event> EventQueue::pop(const std::chrono::seconds &duration) {
    std::unique_lock<std::mutex> lock(mtx);
    if (cv.wait_for(lock, duration, [this](){ return this->queue.empty() == false; })) {
	auto event = queue.front();
	queue.pop();
	return event;
    }
    return nullptr;
};


