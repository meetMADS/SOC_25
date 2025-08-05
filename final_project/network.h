#ifndef NETWORK_H
#define NETWORK_H

#include "node.h"
#include <map>
#include <vector>
#include <string>

// Forward declaration
class Simulator;

class Network {
private:
    std::map<int, Node*> nodes_;
    std::map<int, int> topology_;
    Simulator* simulator_;

public:
    Network(Simulator* sim);
    ~Network();

    void addNode(Node* node);
    Node* getNode(int id);
    void connect(int node1_id, int node2_id);
    void transportPacket(Node* sender, int nextHopID, Packet* packet);

    void log(const std::string& message);
};

#endif