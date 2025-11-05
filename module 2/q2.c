# Finding min and max in bst


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return createNode(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

int findMin(struct Node* root) {
    while (root->left) root = root->left;
    return root->data;
}

int findMax(struct Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

int main() {
    struct Node *root = NULL;
    root = insert(root, 40);
    insert(root, 20); insert(root, 10);
    insert(root, 60); insert(root, 80);
    printf("Min = %d\n", findMin(root));
    printf("Max = %d\n", findMax(root));
}
