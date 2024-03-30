#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>
void bubleSort(int arr[], int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	printf("\n Sorted Array by Bubble: \n");
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
	int arrbub[5000];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
		arrbub[i] = arr[i];
	}
	bubleSort(arr, n);
}

