#include<stdio.h>
#include<stdlib.h>

#define MAX 105
#define MAXX 105*105
int m, n;
int arr[MAX][MAX];
int vis[MAX][MAX];
int f=0, l=0;
int tr[4]={1, 0, -1, 0};
int tc[4]={0, -1, 0, 1};
int fans;



typedef struct{
    int first;
    int second;
    int third;
}pair;

pair q[MAXX];

void enqueue(int a, int b, int c){
    q[l].first=a;
    q[l].second=b;
    q[l].third=c;
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



int main(){
    scanf("%d %d", &m, &n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
            vis[i][j]=0;
            if(arr[i][j]==2){
                enqueue(i, j, 0);
            }
        }
    }
    
    while(!isempty()){
        pair an=dequeue();
        int r=an.first;
        int c=an.second;
        int t=an.third;
        fans=t;
        for(int i=0;i<4;i++){
            int cr=r+tr[i];
            int cc=c+tc[i];
            if(cr>=0 && cr<m && cc>=0 && cc<n && arr[cr][cc]==1){
                arr[cr][cc]=2;
                enqueue(cr, cc, t+1);
                
            }
        }
        
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                printf("%d", -1);
                return 0;
            }
        }
    }
    
    
    printf("%d", fans);
    return 0;
    
    
    
    
}
