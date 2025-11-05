# Implementation of skip for storing integers


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LEVEL 3   // maximum number of levels

struct Node {
    int data;
    struct Node **forward;   // array of pointers for multiple levels
};

struct Node* createNode(int level, int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->forward = (struct Node**)malloc(sizeof(struct Node*) * (level + 1));
    for (int i = 0; i <= level; i++)
        node->forward[i] = NULL;
    return node;
}

int randomLevel() {
    int level = 0;
    while (rand() % 2 && level < MAX_LEVEL) level++;
    return level;
}

struct Node *header;

void insert(int data) {
    struct Node *update[MAX_LEVEL + 1];
    struct Node *current = header;
    for (int i = MAX_LEVEL; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->data < data)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (!current || current->data != data) {
        int lvl = randomLevel();
        struct Node *newNode = createNode(lvl, data);
        for (int i = 0; i <= lvl; i++) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }
}

int search(int data) {
    struct Node *current = header;
    for (int i = MAX_LEVEL; i >= 0; i--) {
        while (current->forward[i] && current->forward[i]->data < data)
            current = current->forward[i];
    }
    current = current->forward[0];
    return current && current->data == data;
}

void display() {
    printf("\nSkip List Levels:\n");
    for (int i = MAX_LEVEL; i >= 0; i--) {
        struct Node *node = header->forward[i];
        printf("Level %d: ", i);
        while (node) {
            printf("%d ", node->data);
            node = node->forward[i];
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    header = createNode(MAX_LEVEL, -1);

    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    printf("\nSearching 30: %s\n", search(30) ? "Found" : "Not Found");
    printf("Searching 15: %s\n", search(15) ? "Found" : "Not Found");
    return 0;
}
