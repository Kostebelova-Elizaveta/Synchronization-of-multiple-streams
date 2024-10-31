#include <iostream>
#include <thread>
#include "EventQueue.h"
#include "DataEvent.h"
#include "StartedEvent.h"
#include "WorkDoneEvent.h"
#include "DeviceA.h"
#include "DeviceB.h"

#include "DeviceEvent.h"

static void read(std::shared_ptr<EventQueue> &queueResults, std::shared_ptr<Device> dev, int &count, int &brokeCount, bool &finished, std::chrono::seconds time_sleep) {
    queueResults->push(std::make_shared<StartedEvent>(dev));
    for (int i =0; i<brokeCount; i++) {
        std::this_thread::sleep_for(time_sleep);
        queueResults->push(std::make_shared<DataEvent>(dev));
    }
    if (count == brokeCount) {
        queueResults->push(std::make_shared<WorkDoneEvent>(dev));
    }
    else {
        std::cout << "Device" << dev->getName() << " IS BROKEN" << std::endl;
    }
    finished = true;
        
}


int main() {
    int countDevA;
    int countDevB;
    int brokeCountDevA;
    int brokeCountDevB;
    std::cout << "Enter the number of data from DeviceA: ";
    std::cin >> countDevA;
    std::cout << "Enter the number of data from DeviceB: ";
    std::cin >> countDevB;
    std::cout << "Enter the number of reading from DeviceA before broke (if device is fine enter the same number of data from DeviceA): ";
    std::cin >> brokeCountDevA;
    std::cout << "Enter the number of reading from DeviceB before broke (if device is fine enter the same number of data from DeviceB): ";
    std::cin >> brokeCountDevB;

    bool finishedA = false;
    bool finishedB = false;
    
    std::shared_ptr<Device> devA = std::make_shared<DeviceA>();
    std::shared_ptr<Device> devB = std::make_shared<DeviceB>();
    std::shared_ptr<EventQueue> queueResults = std::make_shared<EventQueue>();

    std::thread produceDeviceA(read, std::ref(queueResults), std::ref(devA), std::ref(countDevA), std::ref(brokeCountDevA), std::ref(finishedA), std::chrono::seconds(1));
    std::thread produceDeviceB(read, std::ref(queueResults), std::ref(devB), std::ref(countDevB), std::ref(brokeCountDevB), std::ref(finishedB), std::chrono::seconds(5));
    
    while (true) {      
        auto wr = queueResults->pop(std::chrono::seconds(5));
        if (wr) {
            std::cout << wr->ToString() << std::endl;
        }
        else {
            if (finishedA && finishedB) {
                std::cout << "END WORK, queue is empty for more than 5 sec" << std::endl;
                break;
            }
        }  
    }
    produceDeviceA.join();
    produceDeviceB.join();
    return 0;
}

