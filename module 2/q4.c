# Root deletion in max heap


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

void deleteRoot() {
    if (size == 0) return;
    heap[1] = heap[size];
    size--;

    int i = 1;
    while (2*i <= size) {
        int largest = i;
        if (heap[2*i] > heap[largest])
            largest = 2*i;
        if (2*i+1 <= size && heap[2*i+1] > heap[largest])
            largest = 2*i+1;
        if (largest == i) break;

        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        i = largest;
    }
}

void display() {
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
    printf("Heap before deletion:\n");
    display();
    deleteRoot();
    printf("Heap after deleting root:\n");
    display();
    return 0;
}
