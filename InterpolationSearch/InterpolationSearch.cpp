#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int min(int x, int y) {
    return (x < y) ? x : y;
}


int interpolationSearch(int* arr, int a, int b, int x)
{
    int pos;
    if (a <= b && x >= arr[a] && x <= arr[b]) {

        pos = a + (((double)(b - a) / (arr[b] - arr[a])) * (x - arr[a]));


        if (arr[pos] == x) return pos;
        if (arr[pos] < x) return interpolationSearch(arr, pos + 1, b, x);
        if (arr[pos] > x)  return interpolationSearch(arr, a, pos - 1, x);
    }
    return -1;
}

int main()
{
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

    int result = interpolationSearch(arr, 0, n - 1, k);
    if (result != -1) {
        printf("Interpolation: Your element is in position %d\n", result + 1);
    }
    else {
        printf("Binary: Element not found\n");
        printf("Interpolation: Element not found\n");
    }
}

