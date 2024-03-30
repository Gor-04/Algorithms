#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int comparator(const void* p1, const void* p2)
{
    const int(*x)[3] = (const int(*)[3])p1;
    const int(*y)[3] = (const int(*)[3])p2;


    return (*x)[2] - (*y)[2];
}

void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component)
{
    if (parent[component] == component) return component;

    parent[component] = findParent(parent, parent[component]);
    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[], int n)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

void bubbleSort(int arr[][3], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j][2] > arr[j + 1][2]) {
                int temp[3];
                for (int k = 0; k < 3; k++) {
                    temp[k] = arr[j][k];
                    arr[j][k] = arr[j + 1][k];
                    arr[j + 1][k] = temp[k];
                }
            }
        }
    }
}

void Kruskal(int n, int edge[][3])
{
    bubbleSort(edge, n);

    int* parent = (int*)malloc(n * sizeof(int));
    int* rank = (int*)malloc(n * sizeof(int));

    makeSet(parent, rank, n);

    int minCost = 0;

    printf("Kruskal MST\n");
    for (int i = 0; i < n; i++) {
        int v1 = findParent(parent, edge[i][0]);
        int v2 = findParent(parent, edge[i][1]);
        int wt = edge[i][2];

        if (v1 != v2) {
            unionSet(v1, v2, parent, rank, n);
            minCost += wt;
            printf("%d -- %d == %d\n", edge[i][0], edge[i][1], wt);
        }
    }

    printf("MST is : %d\n", minCost);

    free(parent);
    free(rank);
}

int main()
{
    int edge[5][3] = { { 0, 1, 10 },
                       { 0, 2, 6 },
                       { 0, 3, 5 },
                       { 1, 3, 15 },
                       { 2, 3, 4 } };

    Kruskal(5, edge);

    return 0;
}
