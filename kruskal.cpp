#include <iostream>
#include <climits>
using namespace std;

int minCost, cost[100][100], parent[100], i, j, x, y, n;

void findMin();
int checkCycle(int x, int y);

int main() {
    int count = 0, totalCost = 0, flag = 0;

    cout << "Enter the number of towns: ";
    cin >> n;

    cout << "Enter the cost matrix" << endl;
    cout << "Enter 999 for No edges and self-loops" << endl;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin >> cost[i][j];

    while (count != n - 1 && minCost != 999) {
        findMin();
        flag = checkCycle(x, y);

        if (flag == 1) {
            cout << x << " -----> " << y << " == " << cost[x][y] << endl;
            count++;
            totalCost += cost[x][y];
        }

        cost[x][y] = cost[y][x] = 999;
    }

    cout << "The total cost of the least expensive tree = " << totalCost << endl;

    return 0;
}

void findMin() {
    minCost = INT_MAX;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (cost[i][j] < minCost && i != j) {
                minCost = cost[i][j];
                x = i;
                y = j;
            }
}

int checkCycle(int x, int y) {
    if ((parent[x] == parent[y]) && (parent[x] != 0))
        return 0;
    else if (parent[x] == 0 && parent[y] == 0)
        parent[x] = parent[y] = x;
    else if (parent[x] == 0)
        parent[x] = parent[y];
    else if (parent[x] != parent[y])
        parent[y] = parent[x];

    return 1;
}
