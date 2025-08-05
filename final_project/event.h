#ifndef EVENT_H
#define EVENT_H

#include "network.h"
#include "packet.h"

class Event {
public:
    const double time;
    Event(double t) : time(t) {}
    virtual ~Event() {}
    virtual void execute(Simulator* sim) = 0;
};

class PacketArrivalEvent : public Event {
private:
    Packet* packet_;
    Node* targetNode_;

public:
    PacketArrivalEvent(double time, Packet* p, Node* n)
        : Event(time), packet_(p), targetNode_(n) {}
    ~PacketArrivalEvent() {
    }

    void execute(Simulator* sim) override {
        targetNode_->handlePacket(packet_);
    }
};

#endif