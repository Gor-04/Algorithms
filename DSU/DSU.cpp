#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct DisjointSet {
    int* parent; 
    int* rank;   
    int n;       
};

struct DisjointSet* createDisjointSet(int n) {
    struct DisjointSet* ds = (struct DisjointSet*)malloc(sizeof(struct DisjointSet));
    if (ds == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    ds->n = n;
    ds->parent = (int*)malloc(n * sizeof(int));
    ds->rank = (int*)malloc(n * sizeof(int));

    if (ds->parent == NULL || ds->rank == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    
    for (int i = 0; i < n; ++i) {
        ds->parent[i] = i;
        ds->rank[i] = 0;
    }

    return ds;
}
int find(struct DisjointSet* ds, int x) {
    if (ds->parent[x] != x)
        ds->parent[x] = find(ds, ds->parent[x]);
    return ds->parent[x];
}

void unionSets(struct DisjointSet* ds, int x, int y) {
    int xroot = find(ds, x);
    int yroot = find(ds, y);

    if (ds->rank[xroot] < ds->rank[yroot]) ds->parent[xroot] = yroot;
    else if (ds->rank[xroot] > ds->rank[yroot]) ds->parent[yroot] = xroot;
    else {
        ds->parent[yroot] = xroot;
        ds->rank[xroot]++;
    }
}
void printDSU(struct DisjointSet* ds) {
    printf("Parent Array: ");
    for (int i = 0; i < ds->n; ++i) {
        printf("%d ", ds->parent[i]);
    }
    printf("\n");
}

int main() {
    int n = 5; 
    struct DisjointSet* ds = createDisjointSet(n);

    unionSets(ds, 0, 1);
    unionSets(ds, 2, 3);
    unionSets(ds, 0, 4);
    printDSU(ds);
    printf("Element: ");
    for (int i = 0; i < n; ++i)
        printf("%d ", i);
    printf("\nRepresentative: ");
    for (int i = 0; i < n; ++i)printf("%d ", find(ds, i));
    printf("\n");

    free(ds->parent);
    free(ds->rank);
    free(ds);

    return 0;
}