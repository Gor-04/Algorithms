#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void BucketSort(int* arr, int n) {
    if (n <= 0) return;

    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (mx < arr[i]) mx = arr[i];
    }
    unsigned* bucket = (unsigned*)calloc(mx + 1, sizeof(unsigned));
    if (bucket == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    
    int cur = 0; 
    for (int i = 0; i <= mx; i++) {
 
        while (bucket[i] > 0) {
            arr[cur++] = i; 
            bucket[i]--;  
        }
    }


    free(bucket);
}

int main() {
    int array[100], num;

    printf("Enter the size of array: ");
    scanf("%d", &num);

    if (num <= 0 || num > 100) {
        printf("Invalid input size. Please enter a positive integer less than or equal to 100.\n");
        return 1;
    }

    printf("Enter %d elements to be sorted:\n", num);
    for (int i = 0; i < num; i++)
        scanf("%d", &array[i]);

    printf("\nThe array of elements before sorting: \n");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);

    BucketSort(array, num);

    printf("\nThe array of elements after sorting: \n");
    for (int i = 0; i < num; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
