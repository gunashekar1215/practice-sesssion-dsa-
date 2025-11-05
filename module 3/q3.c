# implement dis-joint


#include <stdio.h>

#define MAX 10
int parent[MAX];

// find root of element with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

// union two sets
void unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootY] = rootX;
}

int main() {
    int i;
    for (i = 0; i < MAX; i++)
        parent[i] = i; // initialize each node as its own parent

    unionSet(1, 2);
    unionSet(2, 3);
    unionSet(4, 5);
    unionSet(3, 5);

    printf("Find(5) = %d\n", find(5));
    printf("Find(2) = %d\n", find(2));

    if (find(1) == find(5))
        printf("1 and 5 are in the same set\n");
    else
        printf("1 and 5 are in different sets\n");

    return 0;
}
