#include <stdio.h>

int parent[100005];
int sz[100005];

void init(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    sz[a] += sz[b];
}

int main() {
    init(5);

    unite(1, 2);
    unite(2, 3);

    printf("%d\n", find(1) == find(3)); 
}
