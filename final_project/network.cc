#include "network.h"
#include "simulator.h" 

Network::Network(Simulator* sim) : simulator_(sim) {}

Network::~Network() {
    for (auto const& [id, node] : nodes_) {
        delete node;
    }
}

void Network::addNode(Node* node) {
    nodes_[node->id] = node;
    node->network = this;
}

Node* Network::getNode(int id) {
    return nodes_.at(id);
}

void Network::connect(int node1_id, int node2_id) {
    topology_[node1_id] = node2_id;
    topology_[node2_id] = node1_id;
}

void Network::log(const std::string& message) {
    simulator_->log(message);
}

void Network::transportPacket(Node* sender, int nextHopID, Packet* packet) {
    Node* receiver = getNode(nextHopID);
    double const delay = 10.0;
    double arrivalTime = simulator_->getCurrentTime() + delay;
    Event* event = new PacketArrivalEvent(arrivalTime, packet, receiver);
    simulator_->schedule(event);
}