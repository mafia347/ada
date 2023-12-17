#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int MAX_VERTICES = 100; // Adjust the maximum number of vertices as needed

class Graph {
public:
    void addEdge(int u, int v);
    void bfs(int startVertex);
    unordered_map<int, int*> getAdjacencyList(); // Added accessor method

private:
    unordered_map<int, int*> adjacencyList; // Using dynamic arrays for adjacency lists
};

void Graph::addEdge(int u, int v) {
    if (adjacencyList.find(u) == adjacencyList.end()) {
        adjacencyList[u] = new int[MAX_VERTICES];
        fill_n(adjacencyList[u], MAX_VERTICES, -1); // Initialize the array with -1
    }

    int* neighbors = adjacencyList[u];
    while (*neighbors != -1) {
        ++neighbors;
    }
    *neighbors = v;
}

void Graph::bfs(int startVertex) {
    unordered_set<int> visited;
    queue<int> vertexQueue;

    cout << "Vertices reachable from " << startVertex << " using BFS: ";

    vertexQueue.push(startVertex);
    visited.insert(startVertex);

    while (!vertexQueue.empty()) {
        int currentVertex = vertexQueue.front();
        vertexQueue.pop();

        cout << currentVertex << " ";

        int* neighbors = adjacencyList[currentVertex];
        while (*neighbors != -1) {
            int neighbor = *neighbors;
            if (visited.find(neighbor) == visited.end()) {
                vertexQueue.push(neighbor);
                visited.insert(neighbor);
            }
            ++neighbors;
        }
    }

    cout << endl;
}

// Accessor method to retrieve the adjacency list
unordered_map<int, int*> Graph::getAdjacencyList() {
    return adjacencyList;
}

int main() {
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    int startVertex = 2;

    g.bfs(startVertex);

    // Clean up dynamic arrays
    auto adjacencyList = g.getAdjacencyList();
    for (auto& pair : adjacencyList) {
        delete[] pair.second;
    }

    return 0;
}