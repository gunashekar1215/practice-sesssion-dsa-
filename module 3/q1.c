# Find words usisng tie


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ALPHABET 26

struct TrieNode {
    struct TrieNode *child[ALPHABET];
    bool end;
};

struct TrieNode* newNode() {
    struct TrieNode *node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->end = false;
    for (int i=0; i<ALPHABET; i++) node->child[i] = NULL;
    return node;
}

void insert(struct TrieNode *root, char *word) {
    struct TrieNode *p = root;
    for (int i=0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!p->child[idx]) p->child[idx] = newNode();
        p = p->child[idx];
    }
    p->end = true;
}

bool search(struct TrieNode *root, char *word) {
    struct TrieNode *p = root;
    for (int i=0; word[i]; i++) {
        int idx = word[i] - 'a';
        if (!p->child[idx]) return false;
        p = p->child[idx];
    }
    return p->end;
}

int main() {
    struct TrieNode *root = newNode();
    insert(root, "cat");
    insert(root, "car");
    insert(root, "dog");

    printf("Search cat → %s\n", search(root,"cat") ? "Found" : "Not Found");
    printf("Search bat → %s\n", search(root,"bat") ? "Found" : "Not Found");
}
