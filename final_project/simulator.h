#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "event.h"
#include <queue>
#include <vector>
#include <iostream>
#include <iomanip>

struct EventComparator {
    bool operator()(const Event* a, const Event* b) const {
        return a->time > b->time;
    }
};

// The core simulation engine.
class Simulator {
private:
    double currentTime_ = 0.0;
    std::priority_queue<Event*, std::vector<Event*>, EventComparator> eventQueue_;

public:
    ~Simulator();
    
    double getCurrentTime() const { return currentTime_; }
    void schedule(Event* event);
    void run();

    void log(const std::string& message);
};

#endif