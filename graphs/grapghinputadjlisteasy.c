#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005   // Maximum number of vertices

int n, m;           // Number of vertices and edges
int *adj[MAXN];     // Array of pointers to store neighbors
int deg[MAXN];      // Degree (number of neighbors) of each vertex

// Function to add an undirected edge
void addEdge(int u, int v) {
    // Add v to u's adjacency list
    adj[u] = realloc(adj[u], (deg[u] + 1) * sizeof(int));
    adj[u][deg[u]++] = v;

    // Add u to v's adjacency list
    adj[v] = realloc(adj[v], (deg[v] + 1) * sizeof(int));
    adj[v][deg[v]++] = u;
}

int main() {
    scanf("%d %d", &n, &m); // Input: number of vertices and edges

    // Initialize adjacency list
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        deg[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }



    return 0;
}
