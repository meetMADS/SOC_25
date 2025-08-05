#include "node.h"
#include "network.h" 

void Host::handlePacket(Packet* packet) {
    network->log("Host " + std::to_string(id) + " received message: '" + packet->message + "' from Host " + std::to_string(packet->sourceID));
    
    delete packet;
}

void Host::send(int destinationID, const std::string& message) {
    Packet* packet = new Packet{id, destinationID, message};
    network->log("Host " + std::to_string(id) + " is sending a packet to Host " + std::to_string(destinationID));
    network->transportPacket(this, 1, packet);
}

void Router::handlePacket(Packet* packet) {
    network->log("Router " + std::to_string(id) + " received a packet for Host " + std::to_string(packet->destinationID));
    int nextHopID = -1;
    if (packet->destinationID == 2) {
        nextHopID = 2;
    }
    if (nextHopID != -1) {
        network->log("Router " + std::to_string(id) + " is forwarding the packet to Host " + std::to_string(nextHopID));
        network->transportPacket(this, nextHopID, packet);
    }
}