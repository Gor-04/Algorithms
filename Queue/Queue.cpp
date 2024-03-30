#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int tail = -1;

int peek(int* q) {
    if (tail == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q[0];
}

int enqueue(int* q, int x, int n) {
    if (tail == n - 1) {
        printf("Queue is full!\n");
        return 0;
    }
    tail++;
    q[tail] = x;
    return 1;
}

int dequeue(int* q) {
    if (tail == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int temp = q[0];
    for (int i = 0; i < tail; i++) {
        q[i] = q[i + 1];
    }
    tail--;
    return temp;
}

void print(int* q) {
    if (tail == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = 0; i <= tail; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    int* q = (int*)malloc(n * sizeof(int));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    if (enqueue(q, 10, n)) {
        printf("Element 10 enqueued successfully.\n");
    }
    else {
        printf("Failed to enqueue element 10. Queue is full.\n");
    }

    if (enqueue(q, 20, n)) {
        printf("Element 20 enqueued successfully.\n");
    }
    else {
        printf("Failed to enqueue element 20. Queue is full.\n");
    }

    if (enqueue(q, 30, n)) {
        printf("Element 30 enqueued successfully.\n");
    }
    else {
        printf("Failed to enqueue element 30. Queue is full.\n");
    }

    if (enqueue(q, 40, n)) {
        printf("Element 40 enqueued successfully.\n");
    }
    else {
        printf("Failed to enqueue element 40. Queue is full.\n");
    }

    dequeue(q);
    dequeue(q);
    

    print(q);

    free(q);

    return 0;
}

