#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<list<int>> adjacencyList;

public:
    Graph(int V) : vertices(V), adjacencyList(V) {}

    void addEdge(int from, int to) {
        adjacencyList[from].push_back(to);
    }

    void DFSUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjacencyList[vertex]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(vertices, false);
        cout << "DFS starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    g.DFS(0);

    return 0;
}
