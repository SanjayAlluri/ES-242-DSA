#include <stdio.h>
#include <stdlib.h>

#define MAXN 1005   

int n, m;          
int *adj[MAXN];    
int deg[MAXN];    
int visited[MAXN];

void addEdge(int u, int v) {
    adj[u] = realloc(adj[u], (deg[u] + 1) * sizeof(int));
    adj[u][deg[u]++] = v;

    adj[v] = realloc(adj[v], (deg[v] + 1) * sizeof(int));
    adj[v][deg[v]++] = u;
}

void DFS(int u) {
    visited[u] = 1;
    printf("%d ", u); 

    for (int i = 0; i < deg[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            DFS(v);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
        deg[i] = 0;
        visited[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    return 0;
}
