#include <stdio.h>
#include <stdlib.h>

typedef struct bst {
    int key;
    struct bst *left, *right;
} BST;

BST *newNode(int key) {
    BST *n = malloc(sizeof(BST));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

BST *insert(BST *root, int key) {
    if (!root) return newNode(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

BST *findMin(BST *root) {
    while (root && root->left) root = root->left;
    return root;
}

BST *findMax(BST *root) {
    while (root && root->right) root = root->right;
    return root;
}

BST *delete(BST *root, int key) {
    if (!root) return NULL;
    if (key < root->key) root->left = delete(root->left, key);
    else if (key > root->key) root->right = delete(root->right, key);
    else {
        if (!root->left) { BST *r = root->right; free(root); return r; }
        if (!root->right){ BST *l = root->left;  free(root); return l; }
        BST *m = findMin(root->right);
        root->key = m->key;
        root->right = delete(root->right, m->key);
    }
    return root;
}

BST *search(BST *root, int key) {
    while (root && root->key != key)
        root = key < root->key ? root->left : root->right;
    return root;
}

/* Successor: next greater key than `key`. Works even if `key` not present. */
BST *successor(BST *root, int key) {
    BST *succ = NULL;
    BST *cur = root;

    while (cur) {
        if (key < cur->key) {
            succ = cur;            // cur is a candidate successor
            cur = cur->left;
        } else if (key > cur->key) {
            cur = cur->right;
        } else { // found exact node
            if (cur->right) return findMin(cur->right);
            return succ;
        }
    }
    return succ;
}

/* Predecessor: next smaller key than `key`. Works even if `key` not present. */
BST *predecessor(BST *root, int key) {
    BST *pred = NULL;
    BST *cur = root;

    while (cur) {
        if (key > cur->key) {
            pred = cur;            // cur is a candidate predecessor
            cur = cur->right;
        } else if (key < cur->key) {
            cur = cur->left;
        } else { // found exact node
            if (cur->left) return findMax(cur->left);
            return pred;
        }
    }
    return pred;
}

void inorder(BST *root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

int main() {
    int data[] = {5, 4, 1, 10, 9, 3, 15, 2, 6};
    BST *root = NULL;

    for (int i = 0; i < 9; i++) root = insert(root, data[i]);
    inorder(root); printf("\n");

    for (int i = 0; i < 9; i += 2) root = delete(root, data[i]);
    inorder(root); printf("\n");

    int keys[] = {3, 7, 10, 15};
    for (int i = 0; i < 4; ++i) {
        int k = keys[i];
        BST *s = successor(root, k);
        BST *p = predecessor(root, k);
        printf("key=%d -> succ=%s pred=%s\n",
               k,
               s ? ({ static char buf[32]; snprintf(buf, sizeof buf, "%d", s->key); buf; }) : "NULL",
               p ? ({ static char buf2[32]; snprintf(buf2, sizeof buf2, "%d", p->key); buf2; }) : "NULL");
    }

    return 0;
}
