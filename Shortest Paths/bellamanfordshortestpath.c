#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define MAX 1005
#define MAXX 100005
int dist[MAX];
int parent[MAX];
int path[MAX];
int idx=0;

typedef struct{
    int first;
    int second;
    int third;
}tuple;

tuple arr[MAXX];

int n, m;int f=0;int s;int t;

void addinto(int u, int v, int w){
    arr[f].first=u;
    arr[f].second=v;
    arr[f].third=w;
    f++;
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addinto(u, v, w);
    }
    
    for(int i=0;i<n;i++){
        dist[i]=INT_MAX;   
    }
    
    scanf("%d", &s);
    scanf("%d", &t);
    dist[s]=0;
    parent[s]=-1;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            tuple ans=arr[j];
            int u=ans.first;
            int v=ans.second;
            int w=ans.third;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        tuple ans=arr[i];
            int u=ans.first;
            int v=ans.second;
            int w=ans.third;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                printf("Negative Cycle");
                return 0;
            }
    }
    
    if(dist[t]==INT_MAX){
        printf("%d", -1);
        return 0;
    }
    else{
        path[idx++]=t;
        int temp=parent[t];
        while(temp!=-1){
            path[idx++]=temp;
            temp=parent[temp];
        }
    }
    printf("%d\n", dist[t]);
    for(int i=idx-1;i>=0;i--){
        printf("%d ", path[i]);
    }printf("\n");

    
    
}
