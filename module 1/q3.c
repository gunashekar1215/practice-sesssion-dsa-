# Multiplication of two polynomials

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node* insert(struct Node *head, int c, int e) {
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = c; temp->exp = e; temp->next = NULL;
    if (!head) return temp;
    struct Node *ptr = head;
    while (ptr->next) ptr = ptr->next;
    ptr->next = temp;
    return head;
}

struct Node* multiply(struct Node *p1, struct Node *p2) {
    struct Node *res = NULL;
    for (struct Node *a = p1; a; a = a->next)
        for (struct Node *b = p2; b; b = b->next)
            res = insert(res, a->coeff * b->coeff, a->exp + b->exp);
    return res;
}

void display(struct Node *head) {
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head) printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL, *res = NULL;
    p1 = insert(p1, 2, 1); p1 = insert(p1, 3, 0);
    p2 = insert(p2, 1, 1); p2 = insert(p2, 4, 0);
    res = multiply(p1, p2);
    printf("Product: "); display(res);
}
