# Multi linked structure

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *right, *down;
};

int main() {
    struct Node *n1=malloc(sizeof(struct Node));
    struct Node *n2=malloc(sizeof(struct Node));
    struct Node *n3=malloc(sizeof(struct Node));
    struct Node *n4=malloc(sizeof(struct Node));

    n1->data=1; n2->data=2; n3->data=3; n4->data=4;

    n1->right = n2; n1->down = n3;
    n2->right = NULL; n2->down = n4;
    n3->right = n4; n3->down = NULL;
    n4->right = NULL; n4->down = NULL;

    printf("%d %d\n", n1->data, n1->right->data);
    printf("%d %d\n", n1->down->data, n1->down->right->data);
    return 0;
}
