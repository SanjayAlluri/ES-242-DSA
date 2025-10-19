#include<stdio.h>
#include<stdlib.h>

#define MAX 105
#define MAXX 100005
int m, n;
int arr[MAX][MAX];
int vis[MAX][MAX];
int f=0, l=0;
int fans=0;
int ans=0;
int tr[4]={1, 0, -1, 0};
int tc[4]={0, -1, 0, 1};

typedef struct{
    int first;
    int second;
}pair;

pair q[MAXX];

void enqueue(int a, int b){
    q[l].first=a;
    q[l].second=b;
    l++;
    l=l%MAXX;
}

pair dequeue(){
    pair ans=q[f];
    f++; f=f%MAXX;
    return ans;
}

int isempty(){
    return f==l;
}


int bfs(int i, int j){
    int ans=0;
    enqueue(i, j);
    vis[i][j]=1;
    while(!isempty()){
        pair temp=dequeue();
        int r=temp.first;
        int c=temp.second;
        ans=ans+1;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int cr=r+tr[i];
            int cc=c+tc[i];
            if(cr>=0 && cr<m && cc>=0 && cc<n){
                if(!vis[cr][cc] && arr[cr][cc]==1){
                    enqueue(cr, cc);
                    vis[cr][cc]=1;
                }
            }
            
        }
        
        
    }
    return ans;
}



int main(){
    scanf("%d %d", &m, &n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
            vis[i][j]=0;
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && arr[i][j]==1){
                ans=bfs(i, j);
                if(fans<ans){
                    fans=ans;
                }
            }
        }
    }
    
    printf("%d", fans);
    
    
}
