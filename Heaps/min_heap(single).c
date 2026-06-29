#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int MAXI=10000;

int min_heap[10000];
int curr_size=0;

void heapify_down(int idx){
    int r_idx=2*idx+2;
    int l_idx=2*idx+1;
    int curr=min_heap[idx];
    int val=curr;
    int i=idx;
    if(r_idx<curr_size){
        if(min_heap[r_idx]<curr){
            val=min_heap[r_idx];
            i=r_idx;
        }
    }
    if(l_idx<curr_size){
        if(min_heap[l_idx]<val){
            val=min_heap[l_idx];
            i=l_idx;
        }
    }
    if(val==curr){
        return ;
    }
    int temp=curr;
    min_heap[idx]=val;
    min_heap[i]=curr;
    heapify_down(i);
}


void heapify_up(int idx){
    if(idx==0){
        return ;
    }
    int par=(idx-1)/2;
    if(min_heap[idx]<min_heap[par]){
        int temp=min_heap[par];
        int temp2=min_heap[idx];
        min_heap[par]=temp2;
        min_heap[idx]=temp;
        heapify_up(par);
    }
    else{
        return ;
    }
}

void insert(int n){
    min_heap[curr_size]=n;
    heapify_up(curr_size);
    curr_size++;
}

int empty(){
    return curr_size==0;
}

int top(){
    return min_heap[0];
}

void pop(){
    int temp=min_heap[curr_size-1];
    min_heap[0]=temp;
    curr_size--;
    heapify_down(0);
}

int main() {
	int arr[]={9, 8, 7, 6};
	for(int i=0;i<4;i++){
	    insert(arr[i]);
	}
	while(!empty()){
	    printf("%d ", top());
	    pop();
	}
}

