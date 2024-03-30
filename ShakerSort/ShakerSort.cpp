#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void ShakerSort(int* arr, int n) {

    int swap = 1;
    int start = 0;
    int end = n - 1;
    int i, temp;
    while (swap)
    {
        swap = 0;
        for (i = start; i < end; ++i)
        {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = 1;
            }
        }
        if (!swap) break;
        swap = 0;
        end--;
        for (int i = end - 1; i >= start; --i)
        {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = 1;
            }
        }
        start++;
    }


}
int main()
{
	printf("\n Number of Elememnts: \n");
	int n; scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; 
    }
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}
	ShakerSort(arr, n);
	printf("\n Sorted Array by Shell: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
    free(arr);

    return 0;
}