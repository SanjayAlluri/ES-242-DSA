#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool issafe(const int* arr, int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int y=abs(arr[j]-arr[i]);
            int x=abs(j-i);
            if(x==y){
                return false;
            }
        }
    }
    return true;
}

void reverse(int *arr, int i, int j){
    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}

bool np(int *arr, int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i+1]>arr[i]){
            index=i;
            break;
        }
    }
    if(index==-1){
        return false;
    }
    for(int i=n-1; i>index;i--){
        if(arr[i]>arr[index]){
            swap(arr, index, i);
            break;

        }
    }

    reverse(arr, index+1, n-1);
    return true;



}

int nqueens(int n){
    int *arr=malloc(n*sizeof(int));
    int count=0;
    for(int i=0;i<n;i++){
        arr[i]=i;
    }
    do{
        if(issafe(arr, n)){
            count++;
        }
    }while(np(arr,n));
    return count;
}




int main(){
    int n;
    scanf("%d", &n);
    int ans;
    ans=nqueens(n);
    printf("The number of solutions are %d", ans);


}
