#include <stdio.h>

#define MAX 100 // max vertices

int V;                  // number of vertices
int matrix[MAX][MAX];   // adjacency matrix
int visited[MAX];       // visited array

// DFS recursive function
void DFS(int u) {
    visited[u] = 1;        // mark current vertex as visited
    printf("%d ", u);      // process the vertex (here, just print it)

    // Visit all neighbors of u
    for (int v = 0; v < V; v++) {
        if (matrix[u][v] && !visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    int E;
    scanf("%d %d", &V, &E);  // number of vertices and edges

    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            matrix[i][j] = 0;

    // Read edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        matrix[u][v] = 1;
        matrix[v][u] = 1;   // comment this line if graph is directed
    }

    // Initialize visited array
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // Start DFS from vertex 0 (or any other vertex)
    DFS(0);

    return 0;
}
