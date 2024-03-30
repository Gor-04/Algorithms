#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
	printf("\n Sorted Array by Selection: \n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main()
{

	printf("Enter the number of elements: ");
	int n; scanf("%d", &n);
	int arr[5000];
	int arrselect[5000];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arrselect[i] = arr[i];
	}
	selectionSort(arr, n);
}
