#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}
int binary_search(int* arr, int l, int r, int k) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) {
            return mid;
        }
        if (arr[mid] > k) {
            return binary_search(arr, l, mid - 1, k);
        }
        return binary_search(arr, mid + 1, r, k);
    }
    return -1;
}
void exp_search(int* arr, int n, int k) {
    int i = 1;
    if (arr[0] == k) {
        printf("Exp: Your element is at 1st position\n");
        return;
    }
    while (i < n && arr[i] <= k) {
        i *= 2;
    }

    int result = binary_search(arr, i / 2, min(i, n - 1), k);

    if (result != -1) {
        printf("Exp: Your element is in position %d\n", result + 1);
    }
    else {
        printf("Exp: Element not found\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Error: Failed to allocate memory\n");
        return 1;
    }

    printf("Enter %d elements of the array: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter the target element: ");
    scanf("%d", &k);
    exp_search(arr, n, k);

    free(arr);
    return 0;
}
