#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_TOWNS = 1000; // Adjust the maximum number of towns as needed

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};

// Comparison function for sorting edges based on their weights
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class KruskalMST {
private:
    int n; // Number of towns
    Edge edges[MAX_TOWNS * (MAX_TOWNS - 1) / 2]; // Array to store edges
    int parent[MAX_TOWNS]; // Parent array for union-find
    int edgeCount = 0; // Track the number of edges added

public:
    KruskalMST(int numberOfTowns) : n(numberOfTowns) {
        // Initialize parent array
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges[edgeCount++] = {u, v, weight};
    }

    // Function to find the parent of a set (using path compression)
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Function to perform union of two sets (using rank)
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        parent[rootX] = rootY;
    }

    // Function to find the minimum spanning tree using Kruskal's algorithm
    void kruskalMST() {
        // Sort edges based on their weights
        sort(edges, edges + edgeCount, compareEdges);

        // Array to store the edges in the MST
        Edge result[MAX_TOWNS - 1];
        int edgeCountMST = 0;

        for (int i = 0; i < edgeCount && edgeCountMST < n - 1; ++i) {
            int rootU = find(edges[i].u);
            int rootV = find(edges[i].v);

            // If including this edge does not form a cycle
            if (rootU != rootV) {
                result[edgeCountMST++] = edges[i];
                unionSets(rootU, rootV);
            }
        }

        // Output the edges of the minimum spanning tree
        if (edgeCountMST == n - 1) {
            cout << "Minimum Spanning Tree (MST) Edges:\n";
            for (int i = 0; i < n - 1; ++i) {
                cout << result[i].u << " - " << result[i].v << " : " << result[i].weight << "\n";
            }
        } else {
            cout << "No MST found. Ensure the input is correct.\n";
        }
    }
};

int main() {
    int n; // Number of towns
    cout << "Enter the number of towns: ";
    cin >> n;

    KruskalMST kruskal(n);

    int m; // Number of roads
    cout << "Enter the number of roads: ";
    cin >> m;

    cout << "Enter the details of each road (u v weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        kruskal.addEdge(u, v, weight);
    }

    kruskal.kruskalMST();

    return 0;
}