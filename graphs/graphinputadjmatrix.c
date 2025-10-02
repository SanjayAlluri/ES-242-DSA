#include <stdio.h>

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    int matrix[V][V];

    // Initialize all entries to 0
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            matrix[i][j] = 0;

    // Read edges
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        matrix[src][dest] = 1; // src -> dest
        matrix[dest][src] = 1; // undirected
    }

    // At this point, matrix contains adjacency info

    return 0;
}

