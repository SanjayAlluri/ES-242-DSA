#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

#define MAX 1005
#define MAXX 100005
int dist[MAX];

typedef struct{
    int first;
    int second;
    int third;
}tuple;

tuple arr[MAXX];

int n, m;int f=0;int s;

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
    dist[s]=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            tuple ans=arr[j];
            int u=ans.first;
            int v=ans.second;
            int w=ans.third;
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
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
    
    for(int i=0;i<n;i++){
        if(dist[i]==INT_MAX){dist[i]=-1;}
        printf("%d ", dist[i]);
    }
}
