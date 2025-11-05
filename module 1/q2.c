# Addition of two polynomials


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff, exp;
    struct Node *next;
};

struct Node* insert(struct Node *head, int c, int e) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = c;
    node->exp = e;
    node->next = NULL;
    if (!head) return node;

    struct Node *ptr = head;
    while (ptr->next) ptr = ptr->next;
    ptr->next = node;
    return head;
}

struct Node* add(struct Node *p1, struct Node *p2) {
    struct Node *res = NULL;
    while (p1 && p2) {
        if (p1->exp == p2->exp) {
            res = insert(res, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next; p2 = p2->next;
        } else if (p1->exp > p2->exp) {
            res = insert(res, p1->coeff, p1->exp);
            p1 = p1->next;
        } else {
            res = insert(res, p2->coeff, p2->exp);
            p2 = p2->next;
        }
    }
    while (p1) { res = insert(res, p1->coeff, p1->exp); p1 = p1->next; }
    while (p2) { res = insert(res, p2->coeff, p2->exp); p2 = p2->next; }
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
    struct Node *p1 = NULL, *p2 = NULL, *sum = NULL;
    p1 = insert(p1, 3, 2); p1 = insert(p1, 4, 1); p1 = insert(p1, 5, 0);
    p2 = insert(p2, 6, 1); p2 = insert(p2, 8, 0);

    printf("P1: "); display(p1);
    printf("P2: "); display(p2);

    sum = add(p1, p2);
    printf("Sum: "); display(sum);
}
