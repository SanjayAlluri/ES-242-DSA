#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005   // maximum number of vertices

int n, m;           // number of vertices and edges
int *adj[MAXN];     // adjacency list (dynamic array)
int deg[MAXN];      // degree of each vertex
int visited[MAXN];  // visited array for DFS

// Function to add an undirected edge
void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (deg[u] + 1) * sizeof(int));
    adj[u][deg[u]++] = v;

    adj[v] = realloc(adj[v], (deg[v] + 1) * sizeof(int));
    adj[v][deg[v]++] = u;
}

// DFS function
void DFS(int u) {
    visited[u] = 1;
    printf("%d ", u);  // process vertex (example: print it)

    // Visit all neighbors
    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    // Initialize adjacency list and visited array
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        deg[i] = 0;
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // Run DFS starting from vertex 1 (or any other vertex)
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    return 0;
}
