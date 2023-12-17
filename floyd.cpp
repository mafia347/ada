#include <iostream>
#include <climits> // Added for INT_MAX
#include <chrono>  // Added for timing measurements

using namespace std;

class FloydWarshall {
    int vertices;
    int** adjacencyMatrix;

public:
    FloydWarshall(int v) : vertices(v) {
        adjacencyMatrix = new int*[vertices];
        for (int i = 0; i < vertices; ++i) {
            adjacencyMatrix[i] = new int[vertices];
        }
    }

    void addEdge(int from, int to, int weight) {
        adjacencyMatrix[from][to] = weight;
    }

    void floydAlgorithm() {
        for (int k = 0; k < vertices; ++k) {
            for (int i = 0; i < vertices; ++i) {
                for (int j = 0; j < vertices; ++j) {
                    if (adjacencyMatrix[i][k] != INT_MAX && adjacencyMatrix[k][j] != INT_MAX) {
                        // Check for overflow before updating
                        if (adjacencyMatrix[i][j] > adjacencyMatrix[i][k] + adjacencyMatrix[k][j]) {
                            adjacencyMatrix[i][j] = adjacencyMatrix[i][k] + adjacencyMatrix[k][j];
                        }
                    }
                }
            }
        }
    }

    void displayShortestPaths() {
        cout << "Shortest Paths Matrix:" << endl;
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjacencyMatrix[i][j] == INT_MAX) {
                    cout << "INF ";
                } else {
                    cout << adjacencyMatrix[i][j] << " ";
                }
            }
            cout << endl;
        }
    }

    ~FloydWarshall() {
        for (int i = 0; i < vertices; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of cities and edges: ";
    cin >> vertices >> edges;

    // Start measuring time and space complexity
    auto start_time = chrono::high_resolution_clock::now();

    FloydWarshall graph(vertices);

    // Initialize the adjacency matrix with INF values
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            graph.addEdge(i, j, INT_MAX);
        }
    }

    cout << "Enter the edges and weights (from to weight):" << endl;
    for (int i = 0; i < edges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }

    graph.floydAlgorithm();
    graph.displayShortestPaths();

    // Stop measuring time and space complexity
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    // Output time and space complexity
    cout << "\nTime Complexity: O(V^3)" << endl;
    cout << "Space Complexity: O(V^2)" << endl;
    cout << "Execution Time: " << duration.count() << " microseconds" << endl;

    return 0;
}