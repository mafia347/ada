#include <iostream>
#include<chrono>

using namespace std;

class TransitiveClosure {
    int vertices;
    int** adjacencyMatrix;

public:
    TransitiveClosure(int v) : vertices(v) {
        adjacencyMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjacencyMatrix[i] = new int[vertices];
        }
    }

    void addEdge(int from, int to) {
        adjacencyMatrix[from][to] = 1;
    }

    void warshallAlgorithm() {
        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    adjacencyMatrix[i][j] = adjacencyMatrix[i][j] || (adjacencyMatrix[i][k] && adjacencyMatrix[k][j]);
                }
            }
        }
    }

    void displayTransitiveClosure() {
        cout << "Transitive Closure Matrix:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~TransitiveClosure() {
        for (int i = 0; i < vertices; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    // Start measuring time and space complexity
    auto start_time = chrono::high_resolution_clock::now();

    TransitiveClosure graph(vertices);

    cout << "Enter the edges (from to):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph.addEdge(from, to);
    }

    graph.warshallAlgorithm();
    
    graph.displayTransitiveClosure();

    // Stop measuring time and space complexity
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    // Output time and space complexity
    cout << "\nTime Complexity: O(V^3)" << endl;
    cout << "Space Complexity: O(V^2)" << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}