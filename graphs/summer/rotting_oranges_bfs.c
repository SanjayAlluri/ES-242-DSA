#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct{
    int first;
    int second;
    int third;
}tuple;

tuple q[10005];
int f=0, l=0;

void enqueue(int i, int j, int t){
    q[l].first=i;
    q[l].second=j;
    q[l].third=t;
    l++;
    l=l%10005;
}

void dequeue(){
    f++;
    f=f%10005;
}

tuple top(){
    return q[f];
}

int empty(){
    return f==l;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[n][m];
	int ans=-1;
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        scanf("%d", &arr[i][j]);
	        if(arr[i][j]==2){
	            enqueue(i, j, 0);
	        }
	    }
	}
	int r[4]={0, 1, 0, -1};
	int c[4]={1, 0, -1, 0};
	while(!empty()){
	    tuple curr=top();
	    int i=curr.first;
	    int j=curr.second;
	    int t=curr.third;
	    dequeue();
	    ans=t;
	    for(int a=0;a<4;a++){
	        int ni=i+r[a];
	        int nj=j+c[a];
	        if(ni<0 || ni>=n || nj<0 || nj>=m){
	            continue;
	        }
	        if(arr[ni][nj]==1){
	            arr[ni][nj]=2;
	            enqueue(ni, nj, t+1);
	        }
	    }
	}
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(arr[i][j]==1){
	            printf("%d", -1);
	            return 0;
	        }
	    }
	}
	printf("%d", ans);
}

