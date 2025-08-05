#ifndef PACKET_H
#define PACKET_H

#include <string>

struct Packet {
    int sourceID;
    int destinationID;
    std::string message;
};

#endif