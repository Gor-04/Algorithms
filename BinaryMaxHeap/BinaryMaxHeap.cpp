#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size = 0;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(int *heap, int index, int n) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest])largest = right;
    if (largest != index) 
    {
        swap(&heap[index], &heap[largest]);
        Heapify(heap, largest, n);
    }
}
void insert(int* heap, int value, int n) {
    if (size == n - 1) {
        printf("Heap overflow!\n");
        return;
    }

    size++;
    int i = size - 1;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int extractMax(int *heap, int n) {
    if (size <= 0)
        return -1;

    if (size == 1) {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    Heapify(heap, 0, n);

    return root;
}

int peek(int *heap) {
    if (size <= 0)
        return -1;

    return heap[0];
}
void increaseKey(int *heap, int index, int newValue) {
    if (index >= size) {
        printf("Invalid index!\n");
        return;
    }

    if (newValue < heap[index]) {
        printf("New value is less than current value!\n");
        return;
    }

    heap[index] = newValue;

    while (index != 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}
void print(int* heap, int n) {
    printf("Heap: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the heap: ");
    scanf("%d", &n);

    int* heap = (int*)malloc(n * sizeof(int));
    if (heap == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    insert(heap, 10, n);
    insert(heap, 20, n);
    insert(heap, 30, n);
    insert(heap, 40, n);

    printf("Maximum element in the heap: %d\n", peek(heap)); 

    increaseKey(heap, 2, 50);

    printf("Maximum element in the heap after increasing key: %d\n", peek(heap)); 

    printf("Extracted max element: %d\n", extractMax(heap, n)); 
    printf("Extracted max element: %d\n", extractMax(heap, n)); 
    print(heap, n);
    free(heap);
}

