#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int quick(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);
    for (int j = low; j <= high; j++) {

        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp1 = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp1;
    return i + 1;
}


void quickSort(int arr[], int low, int high) {

    if (low < high) {
        int pi = quick(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main() {
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(unsigned int));
    printf("\n Generated Array: \n");
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%u ", arr[i]);
    }
    printf("\n");
    quickSort(arr, 0, n - 1);
    printf("\n Sorted Array by quicksort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    return 0;
}