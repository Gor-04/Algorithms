#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}



void linear_search(int* arr, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == k) {
            printf("Linear: Your element is in %d position\n", i + 1);
            return;
        }
    }
    printf("Linear: Element not found\n");
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

void rightmost_binary_search(int* arr, int n, int k) {
    int l = 0;
    int r = n - 1;
    int result = -1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == k) {
            result = mid;
            l = mid + 1;
        }
        else if (arr[mid] < k) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    if (result != -1) {
        printf("Rightmost: Your element is in position %d\n", result + 1);
    }
    else {
        printf("Rightmost: Element not found\n");
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

    linear_search(arr, n, k);
    int result = binary_search(arr, 0, n - 1, k);
    if (result != -1) {
        printf("Binary: Your element is in position %d\n", result + 1);
      
    }
    else {
        printf("Binary: Element not found\n");
     
    }
    rightmost_binary_search(arr, n, k);
   

    free(arr);
    return 0;
}
