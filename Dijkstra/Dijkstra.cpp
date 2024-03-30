#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void dijkstra(int graph[10][10], int n, int start) {

    int distance[10], predecessor[10];
    bool visited[10] = { 0 };

    for (int i = 0; i < n; ++i) {
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }

    distance[start] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int min_distance = INT_MAX;
        int current_node = -1;

        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                current_node = j;
            }
        }

        if (current_node == -1)
            break;

        visited[current_node] = 1;

        for (int j = 0; j < n; ++j) {
            int edge_weight = graph[current_node][j];
            if (edge_weight > 0 && distance[current_node] + edge_weight < distance[j]) {
                distance[j] = distance[current_node] + edge_weight;
                predecessor[j] = current_node;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i != start) {
            printf("Distance from source to %d: %d\n", i, distance[i]);
        }
    }
}

int main() {
    int graph[10][10];
    int n, start_vertex;

    printf("Enter the number of vertices in the graph (max %d): ", 10);
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid number of vertices. \n");
        return 1;
    }

    printf("Enter the adjacency matrix representation of the graph:\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", n - 1);
    scanf("%d", &start_vertex);

    if (start_vertex < 0 || start_vertex >= n) {
        printf("Invalid source vertex. Please enter an integer between 0 and %d.\n", n - 1);
        return 1;
    }

    dijkstra(graph, n, start_vertex);

    return 0;
}

