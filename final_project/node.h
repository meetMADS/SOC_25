#ifndef NODE_H
#define NODE_H

#include "packet.h"
#include <iostream>

// Forward declaration to prevent circular dependencies
class Network; 

class Node {
public:
    const int id;
    Network* network; 

    Node(int id) : id(id), network(nullptr) {}
    virtual ~Node() {}

    virtual void handlePacket(Packet* packet) = 0;
};

class Host : public Node {
public:
    Host(int id) : Node(id) {}

    void handlePacket(Packet* packet) override;
    void send(int destinationID, const std::string& message);
};

//forwarding device.
class Router : public Node {
public:
    Router(int id) : Node(id) {}

    void handlePacket(Packet* packet) override;
};
#endif