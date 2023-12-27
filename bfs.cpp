#include <iostream>
#include <list>
#include <queue>
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

    void BFS(int startVertex) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int currentVertex = q.front();
            cout << currentVertex << " ";
            q.pop();

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
