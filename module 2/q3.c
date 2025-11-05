# Max heap


#include <stdio.h>

#define MAX 20
int heap[MAX];
int size = 0;

void insert(int val) {
    size++;
    int i = size;
    heap[i] = val;

    while (i > 1 && heap[i/2] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

void display() {
    printf("Max Heap: ");
    for (int i = 1; i <= size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main() {
    insert(40);
    insert(30);
    insert(50);
    insert(20);
    insert(60);
    display();
    return 0;
}
