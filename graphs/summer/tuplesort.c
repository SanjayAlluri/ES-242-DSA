#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int first;
    int second;
    int third;
}tuple;

int cmp(const void* a, const void* b){
    tuple *t1=(tuple*)a;
    tuple *t2=(tuple*)b;
    return t1->first-t2->first;
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	tuple arr[m];
	for(int i=0;i<m;i++){
	    int u, v, w;
	    scanf("%d %d %d", &u, &v, &w);
	    arr[i].first=u;
	    arr[i].second=v;
	    arr[i].third=w;
	}
	
	qsort(arr, m, sizeof(tuple), cmp);
	for(int i=0;i<m;i++){
	    printf("%d ", arr[i].first);
	}
}

