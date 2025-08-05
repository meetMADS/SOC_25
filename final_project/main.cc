#include "simulator.h"
#include "network.h"
#include "node.h"

int main() {
    // 1. Setup
    Simulator simulator;
    Network network(&simulator);

    // Create the nodes: Host A (ID 0), Router R (ID 1), Host B (ID 2)
    Node* hostA = new Host(0);
    Node* routerR = new Router(1);
    Node* hostB = new Host(2);

    network.addNode(hostA);
    network.addNode(routerR);
    network.addNode(hostB);

    // Connect the nodes: A <--> R <--> B
    network.connect(0, 1);
    network.connect(1, 2);

    // 2. Initial Event
    // We start the simulation by having Host A send a packet to Host B.
    simulator.log("--- Setting up initial packet send from A to B ---");
    // Cast Node* to Host* to access the 'send' method.
    static_cast<Host*>(hostA)->send(2, "Hello from A!");

    // 3. Run
    simulator.run();

    return 0;
}