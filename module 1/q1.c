# Represent a polynomial using linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node* insert(struct Node *head, int c, int e) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c;
    temp->exp = e;
    temp->next = NULL;

    if (head == NULL) return temp;

    struct Node *ptr = head;
    while (ptr->next != NULL) ptr = ptr->next;
    ptr->next = temp;
    return head;
}

void display(struct Node *head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head != NULL) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *poly = NULL;
    poly = insert(poly, 3, 2);
    poly = insert(poly, 5, 1);
    poly = insert(poly, 6, 0);

    printf("Polynomial: ");
    display(poly);
    return 0;
}
