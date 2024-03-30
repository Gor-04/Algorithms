#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>



int minKey(int key[], bool mstSet[], int n) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void MST(int parent[], int** graph, int n) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

void primMST(int** graph,  int n) {
    int parent[5];
    int key[5];
    bool mstSet[5];

    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

   MST(parent, graph, n);
}
void printGraph(int** graph, int n) {
    printf("Initial Graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}


int main() {
     int n = 5;
    int** graph = (int**)malloc(n * sizeof(int*));
  

    for (int i = 0; i < n; i++)
    {
        graph[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    graph[0][1] = 2;
    graph[0][3] = 6;
    graph[1][0] = 2;
    graph[1][2] = 3;
    graph[1][3] = 8;
    graph[1][4] = 5;
    graph[2][1] = 3;
    graph[2][4] = 7;
    graph[3][0] = 6;
    graph[3][1] = 8;
    graph[3][4] = 9;
    graph[4][1] = 5;
    graph[4][2] = 7;
    graph[4][3] = 9;
    printGraph(graph, n);
    primMST(graph, n);

    for (int i = 0; i < n; i++)
    {
        free(graph[i]);
    }
    free(graph);

    return 0;
}