#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 505
int arr[MAX][MAX];
int n, m;


int main(){
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=INT_MAX;
        }
        arr[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        arr[u][v]=w;
    }
    
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][via]!=INT_MAX && arr[via][j]!=INT_MAX && arr[i][via]+arr[via][j]<arr[i][j]){
                    arr[i][j]=arr[i][via]+arr[via][j];
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(arr[i][i]<0){
            printf("N");
            return 0;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==INT_MAX){
                printf("%d ", -1);
            }
            else{
                printf("%d ", arr[i][j]);
            }
        }printf("\n");
    }
    
    
}
