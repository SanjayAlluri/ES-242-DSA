#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void unreachable(){
    abort();
}
int flag=0;
int ans=0;
int arr[100];
int idx=0;
int n;
struct bst {
	int key;
	struct bst *left, *right;
};
struct bst* map[100];
void empty(struct bst **t)
{
	*t = NULL;
}

bool is_empty(struct bst **t)
{
	return *t == NULL;
}

struct bst *node(int k)
{
	struct bst *n = malloc(sizeof(struct bst));
	n->key = k;
	n->left = NULL;
	n->right = NULL;
	return n;
}

struct bst **search(struct bst **root, int key)
{
	while (*root) {
		struct bst *t = *root;

		if (t->key == key)
			return root;

		if (t->key < key)
			root = &(*root)->right;

		if (t->key > key)
			root = &(*root)->left;
	}
	return root;
}

struct bst **min(struct bst **root)
{
	while (*root) {
		struct bst *t = *root;
		if (t->left == NULL)
			return root;
		root = &(*root)->left;
	}
	unreachable();
}

struct bst **max(struct bst **root)
{
	while (*root) {
		struct bst *t = *root;
		if (t->right == NULL)
			return root;
		root = &(*root)->right;
	}
	unreachable();
}

void insert(struct bst **root, int key)
{
	struct bst **t = search(root, key);

	if (!*t)
		*t = node(key);
}

struct bst *unlink(struct bst **node)
{
	struct bst *save = *node;

	if ((*node)->left == NULL)
		*node = (*node)->right;
	else if ((*node)->right == NULL)
		*node = (*node)->left;
	else
		unreachable();

	return save;
		
}

struct bst *delete(struct bst **root, int key)
{
	struct bst **t = search(root, key);

	if (*t) {
		struct bst *p = *t;

		if (p->left == NULL || p->right == NULL)
			return unlink(t);

		struct bst **s = min(&(*t)->right);
		struct bst *m = unlink(s);
		m->left = (*t)->left;
		m->right = (*t)->right;
		*t = m;
		return p;
	}
}

struct bst **successor(struct bst **root, int key)
{
	struct bst **left = NULL;
	struct bst **e = NULL;

	while (*root) {
		struct bst *t = *root;

		if (t->key < key) {
			root = &(*root)->right;
		} else if (t->key > key) {
			left = root;
			root = &(*root)->left;
		} else {
			if ((*root)->right)
				return min(&(*root)->right);
			return left;
		}
	}

	return NULL;
}

struct bst **predecessor(struct bst **root, int key)
{
	struct bst **right = NULL;
	struct bst **e = NULL;

	while (*root) {
		struct bst *t = *root;

		if (t->key < key) {
			right = root;
			root = &(*root)->right;
		} else if (t->key > key) {
			root = &(*root)->left;
		} else {
			if ((*root)->left)
				return max(&(*root)->left);
			return right;
		}
	}

	return NULL;
}

void do_print_set(struct bst *t)
{
	if (t) {
		do_print_set(t->left);
		arr[idx++]=t->key;
		do_print_set(t->right);
	}
}

void print_set(struct bst **root)
{
	printf("{");
	do_print_set(*root);
	printf("}");
}
void check_bst(struct bst* root){
    do_print_set(root);
    for(int i=0;i<idx-1;i++){
        if(arr[i]>arr[i+1]){
            flag=1;
        }
    }
    if(!flag && idx>ans){
        ans=idx;
    }
    flag=0;
    idx=0;
}
void algo(struct bst* root){
    if(root==NULL){
        return;
    }
    check_bst(root);
    algo(root->left);
    algo(root->right);
    return ;
}
int main()
{   scanf("%d", &n);
    for(int i=0;i<100;i++){
        map[i]=NULL;
    }
	int root;
	scanf("%d", &root);
	struct bst *t=node(root);
	map[root]=t;
	for(int i=0;i<n-1;i++){
	    int chi, par;
	    char spec;
	    scanf("%d %c %d", &chi, &spec, &par);
	    struct bst* child=node(chi);
	    map[chi]=child;
	    if(spec=='L'){
	        map[par]->left=map[chi];
	    }
	    else{
	        map[par]->right=map[chi];
	    }
	}
	algo(t);
	printf("%d", ans);
	
	
	return 0;
}
