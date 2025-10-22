/* In this algo we have to focous on three major things 
1. Taking input in the format u, v, w and storing them in adj list.
2. Initializing Min-Heap, Up heapify and Down heapify algorithms, and returning the min element in the heap at the time of calling.
3. Implementing Dijkstra algo and printing the shortest distance between src node and all others or printing the shortest path between two given nodes.
*/

/* main heapify functions to define 
1. define minheap
2. createheap
3. swap
4. heapifyup
5. heapifydown
6. insertheap
7. extractmin
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 1005

typedef struct{
    int first;
    int second;
} pair;

pair* arr[MAX};
int deg[MAX];
int v, e;

// Dijkstra
int dist[MAX];
int parent[MAX;
int vis[MAX];

void addedge(int u, int v, int w){
  arr[u]=realloc(arr[a], (deg[u]+1)*sizeof(int));
  arr[u][deg[u]].first=v;
  arr[u][deg[u]].second=w;
  deg[u]++;
}

void dijkstra(int src){
  for(int i=1;i<=v;i++){
    dist[i]=INT_MAX;
    parent[i]=0;
    vis[i]=0;
  }
  dist[src]=0;
  minheap* heap=createheap(v);
  insertheap(heap, src, 0);
  while(heap->size >0){
    int node=extractmin(heap);
    if(vis[u]){continue ;}
    vis[u]=1;
    for(int i=0;i<deg[node];i++){
      int n=arr[node][i].first;
      int weight=arr[node][i].second;
      if(!vis[n] && dist[node]+weight<dist[n]){
        dist[n]=dist[node]+weight;
        parent[n]=node;
        insertheap(heap, n, dist[n]);
      }
        
    }
  }
  
}

int main(){
  scanf("%d %d", &v, &e);
  for(int i=1;i<=v;i++){
    arr[i]=NULL;
    deg[i]=0;
  }
  for(int i=0;i<e;i++){
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    addegde(u, v, w);
    addege(v, u, w); // If undirected edge
  }
  int src;
  scanf("%d", &src);
  dijkstra(src);
}



