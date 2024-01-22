#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

int minimumKey(int key[], int mstSet[], int n) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < n; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void prim(int graph[MAX_VERTICES][MAX_VERTICES], int n) {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    int mstSet[MAX_VERTICES];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minimumKey(key, mstSet, n);
        mstSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the Minimum Cost Connections
    printf("\nMinimum Cost Connections for Electrical Layout:\n");
    for (int i = 1; i < n; i++)
        printf("House %d <-> House %d    Cost: %d\n", parent[i] + 1, i + 1, graph[i][parent[i]]);
}

int main() {
    int n;

    printf("Enter the number of houses: ");
    scanf("%d", &n);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix for the electrical layout:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prim(graph, n);

    return 0;
}