#include <iostream>
using namespace std;

int max(int a, int b) {
 return (a > b) ? a : b;
}
void warshall(int p[10][10], int n) {
 for (int k = 1; k <= n; k++)
 for (int i = 1; i <= n; i++)
 for (int j = 1; j <= n; j++)
 p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
}
int main() {
 int p[10][10] = {0}, n, e, u, v;
 // Input the number of systems and edges
 cout << "\n Enter the number of systems (vertices):";
 cin >> n;
 cout << "\n Enter the number of connections (edges):";
 cin >> e;
 // Input the connections and populate the adjacency matrix
 for (int i = 1; i <= e; i++) {
 cout << "\n Enter the end systems of connection " << i << ":";
 cin >> u >> v;
 p[u][v] = 1;
 }
 // Display the adjacency matrix
 cout << "\n Matrix of input data: \n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++)
 cout << p[i][j] << "\t";
 cout << "\n";
 }
 // Apply Warshall's algorithm to find transitive closure
 warshall(p, n);
 // Display the transitive closure matrix
 cout << "\n Transitive closure: \n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++)
 cout << p[i][j] << "\t";
 cout << "\n";
 }
 return 0;
}
