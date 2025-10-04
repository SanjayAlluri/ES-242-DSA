#include<stdio.h>
#include<stdlib.h>

#define MAX 100005
int *adj[MAX];
int deg[MAX];
int v, e;
int vis[MAX];
int topo[MAX];
int idx=0;

void addedge(int a, int b){
    adj[a]=realloc(adj[a], (deg[a]+1)*sizeof(int));
    adj[a][deg[a]]=b;
    deg[a]++;
}

void dfs(int node){
    vis[node]=1;
    for(int i=0;i<deg[node];i++){
        int n=adj[node][i];
        if(!vis[n]){
            dfs(n);
        }
    }
    topo[idx++]=node;
}

int main(){
    scanf("%d %d", &v, &e);
    for(int i=1;i<=v;i++){
        adj[i]=NULL;
        deg[i]=0;
        vis[i]=0;
    }
    for(int i=0;i<e;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addedge(a, b);
    }
    for(int i=1;i<=v;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    for(int i=idx-1;i>=0;i--){
        printf("%d ", topo[i]);
    }printf("\n");
}