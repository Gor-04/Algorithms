#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
unsigned left(unsigned i) {
    return i * 2 + 1;
}

unsigned right(unsigned i) {
    return i * 2 + 2;
}

unsigned parent(unsigned i) {
    return (i - 1) / 2;
}

void max_heapify(double* A, unsigned i, unsigned* heap_size) {
    unsigned l = left(i);
    unsigned r = right(i);
    unsigned largest = i;
    if (l < *heap_size && A[l] > A[largest])
        largest = l;
    if (r < *heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i) {
        double tmp = A[i];
        A[i] = A[largest];
        A[largest] = tmp;
        max_heapify(A, largest, heap_size);
    }
}

unsigned build_max_heap(double* A, unsigned n) {
    unsigned heap_size = n;
    for (int i = n / 2 - 1; i >= 0; --i) {
        max_heapify(A, i, &heap_size);
    }
    return heap_size;
}

void heap_sort(double* A, unsigned n) {
    unsigned heap_size = build_max_heap(A, n);
    for (int i = n - 1; i > 0; --i) {
        double tmp = A[i];
        A[i] = A[0];
        A[0] = tmp;
        --heap_size;
        max_heapify(A, 0, &heap_size);
    }
}

int main() {
    int n;
    double* arr = NULL;
    printf("Provide the array size: ");
    scanf("%d", &n);

    arr = (double*)malloc(n * sizeof(double));
    if (arr == NULL) {
        fprintf(stderr, "Error: failed to allocate memory!\n");
        exit(1);
    }

    printf("Provide array elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &arr[i]);
    }

    printf("\nThe initial array is:\n");
    for (int i = 0; i < n; ++i) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
    heap_sort(arr, n);

    printf("\ Heap sorted array is: \n");
    for (int i = 0; i < n; ++i)
        printf("%.2lf ", arr[i]);

    free(arr);

    return 0;
}