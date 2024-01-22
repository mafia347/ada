#include <stdio.h>
#include <limits.h>

#define INF 9999
#define MAX 10

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start);

void DijkstraAlgorithm(int Graph[MAX][MAX], int size, int start) {
    int cost[MAX][MAX], distance[MAX], previous[MAX];
    int visited_nodes[MAX], counter, minimum_distance, next_node, i, j;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (Graph[i][j] == 0)
                cost[i][j] = INF;
            else
                cost[i][j] = Graph[i][j];

    for (i = 0; i < size; i++) {
        distance[i] = cost[start][i];
        previous[i] = start;
        visited_nodes[i] = 0;
    }

    distance[start] = 0;
    visited_nodes[start] = 1;
    counter = 1;

    while (counter < size - 1) {
        minimum_distance = INF;

        for (i = 0; i < size; i++)
            if (distance[i] < minimum_distance && !visited_nodes[i]) {
                minimum_distance = distance[i];
                next_node = i;
            }

        visited_nodes[next_node] = 1;
        for (i = 0; i < size; i++)
            if (!visited_nodes[i])
                if (minimum_distance + cost[next_node][i] < distance[i]) {
                    distance[i] = minimum_distance + cost[next_node][i];
                    previous[i] = next_node;
                }
        counter++;
    }

    printf("\nShortest distances from the source node to all other nodes:\n");
    for (i = 0; i < size; i++)
        if (i != start)
            printf("Distance from %d to %d: %d\n", start, i, distance[i]);
}

int main() {
    int Graph[MAX][MAX], i, j, size, source;

    printf("Enter the number of nodes: ");
    scanf("%d", &size);

    printf("Enter the adjacency matrix for the graph:\n");
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            scanf("%d", &Graph[i][j]);

    printf("Enter the source node: ");
    scanf("%d", &source);

    if (source < 0 || source >= size) {
        printf("Invalid source node. Exiting...\n");
        return 1;
    }

    DijkstraAlgorithm(Graph, size, source);

    return 0;
}