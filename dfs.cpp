#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Network {
public:
    void addConnection(int u, int v);
    void dfs(int startSystem);

private:
    unordered_map<int, unordered_set<int>> adjacencyList;
    unordered_set<int> visited;

    void explore(int system);
};

void Network::addConnection(int u, int v) {
    adjacencyList[u].insert(v);
    adjacencyList[v].insert(u);  // Assuming an undirected network
}

void Network::explore(int system) {
    visited.insert(system);
    cout << system << " ";

    for (int neighbor : adjacencyList[system]) {
        if (visited.find(neighbor) == visited.end()) {
            explore(neighbor);
        }
    }
}

void Network::dfs(int startSystem) {
    cout << "Systems reachable from system " << startSystem << ": ";
    explore(startSystem);
    cout << endl;
}

int main() {
    Network network;

    // Example: Adding connections in the network
    network.addConnection(0, 1);
    network.addConnection(0, 2);
    network.addConnection(1, 3);
    network.addConnection(2, 4);
    network.addConnection(3, 4);

    // Specify the starting system
    int startSystem = 0;

    // Perform DFS and print the result
    network.dfs(startSystem);

    return 0;
}