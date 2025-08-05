#include "simulator.h"

Simulator::~Simulator() {
    while (!eventQueue_.empty()) {
        delete eventQueue_.top();
        eventQueue_.pop();
    }
}

void Simulator::schedule(Event* event) {
    eventQueue_.push(event);
}

void Simulator::run() {
    log("Simulation starting...");
    while (!eventQueue_.empty()) {
        Event* event = eventQueue_.top();
        eventQueue_.pop();

        currentTime_ = event->time;
        event->execute(this);

        delete event; // Cleaning up the event after it has been processed
    }
    log("Simulation finished.");
}

void Simulator::log(const std::string& message) {
    std::cout << "[T=" << std::fixed << std::setprecision(2) << std::setw(6) << currentTime_ << "] " << message << std::endl;
}