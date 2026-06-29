#include <stdio.h>
#include<stdlib.h>
#include<limits.h>


typedef struct{
    int first;
    int second;
}pair;

pair heap[10005];
int curr_size=0;

void heapifyup(int idx){
    if(idx==0){
        return ;
    }
    int par_idx=(idx-1)/2;
    if(heap[par_idx].first>heap[idx].first){
        pair child=heap[idx];
        pair parent=heap[par_idx];
        heap[par_idx]=child;
        heap[idx]=parent;
        heapifyup(par_idx);
    }
    else{
        return ;
    }
}


void heapifydown(int idx){
    int r_idx=2*idx+2;
    int l_idx=2*idx+1;
    int curr=heap[idx].first;
    int i=idx;
    if(r_idx<curr_size){
        if(heap[r_idx].first<curr){
            curr=heap[r_idx].first;
            i=r_idx;
        }
    }
    
    if(l_idx<curr_size){
        if(heap[l_idx].first<curr){
            curr=heap[l_idx].first;
            i=l_idx;
        }
    }
    if(curr==heap[idx].first){
        return ;
    }
    pair parent=heap[idx];
    pair child=heap[i];
    heap[idx]=child;
    heap[i]=parent;
    heapifydown(i);
}

void push(int w, int v){
    heap[curr_size].first=w;
    heap[curr_size].second=v;
    curr_size++;
    heapifyup(curr_size-1);
}

int empty(){
    return curr_size == 0;
}

pair top(){
    return heap[0];
}

void pop(){
    pair temp=heap[curr_size-1];
    heap[0]=temp;
    curr_size--;
    heapifydown(0);
}


pair* adj[10005];
int degree[10005];
int weight[10005];

void addedge(int u, int v, int w){
    adj[u]=realloc(adj[u], (degree[u]+1)*sizeof(pair));
    adj[u][degree[u]].first=v;
    adj[u][degree[u]].second=w;
    degree[u]++;
}

int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	for(int i=1;i<=n;i++){
	    weight[i]=INT_MAX;
	    degree[i]=0;
	}
	
	for(int i=0;i<m;i++){
	    int u, v, w;
	    scanf("%d %d %d", &u, &v, &w);
	    addedge(u, v, w);
	}
	push(0, k);
	weight[k]=0;
	while(!empty()){
	    pair curr=top();
	    pop();
	    int t=curr.first;
	    int node=curr.second;
	    for(int i=0;i<degree[node];i++){
	        int neigh=adj[node][i].first;
	        int dist=adj[node][i].second;
	        if(t!=INT_MAX && (t+dist<weight[neigh])){
	            weight[neigh]=t+dist;
	            push(weight[neigh], neigh);
	        }
	    }
	}
	
	int ans=-1;
	for(int i=1;i<=n;i++){
	    if(weight[i]==INT_MAX){
	        printf("%d", -1);
	        return 0;
	    }
	    if(weight[i]>ans){
	        ans=weight[i];
	    }
	}
	
	printf("%d", ans);
	
}

