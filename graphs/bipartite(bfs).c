#include<stdio.h>
#include<stdlib.h>

#define MAX 100005
int *arr[MAX];
int deg[MAX];
int v, e;
int vis[MAX];
int q[MAX];
int f=0, l=0;

void enqueue(int a){
    q[l]=a;
    l++;
    l=l%MAX;
}

int dequeue(){
    int ans=q[f];
    f++;
    f=f%MAX;
    return ans;
}

int isempty(){
    return l==f;
}

void addedge(int a, int b){
    arr[a]=realloc(arr[a], (deg[a]+1)*sizeof(int));
    arr[a][deg[a]]=b;
    deg[a]++;
    
    arr[b]=realloc(arr[b], (deg[b]+1)*sizeof(int));
    arr[b][deg[b]]=a;
    deg[b]++;
}

int main(){
    scanf("%d %d", &v, &e);
    for(int i=1;i<=v;i++){
        arr[i]=NULL;
        deg[i]=0;
        vis[i]=0;
    }
    
    for(int i=0;i<e;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        addedge(a, b);
    }
    
    
    for(int i=1;i<=v;i++){
        if(vis[i]==0){
            enqueue(i);
            vis[i]=1;
            while(!isempty()){
                int node=dequeue();
                for(int i=0;i<deg[node];i++){
                    int n=arr[node][i];
                    if(vis[n]==0){
                        enqueue(n);
                        if(vis[node]==1){
                            vis[n]=2;
                        }
                        else{
                            vis[n]=1;
                        }
                    }
                    else if(vis[n]==vis[node]){
                        printf("NO");
                        return 0;
                    }
                }
            }
        }
    }
    
    
    printf("YES");
    return 0;
}
