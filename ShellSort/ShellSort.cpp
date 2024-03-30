#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void ShellSort(int * arr, int n) {
	for (int i = n/2; i > 0; i/=2)
	{
		for (int j = i; j < n; j++)
		{
			int temp = arr[j];
			int k;
			for (k = j; k >= i && arr[k - i] > temp; k -= i)
			{
				arr[k] = arr[k - i];
			}
			arr[k] = temp;
		}
	}

}
int main()
{
	printf("\n Number of Elememnts: \n");
	int n; scanf("%d", &n);
	int* arr = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 1000;
	}
	if (arr == NULL) {
		printf("Memory allocation failed.\n");
		return 1;
	}
	ShellSort(arr, n);
	printf("\n Sorted Array by Shell: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr);
}

