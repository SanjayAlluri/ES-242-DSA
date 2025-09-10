#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main(){
    int a[5]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    qsort(a,n,sizeof(int),cmpfunc);

    for(int i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
}
