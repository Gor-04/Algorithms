#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n)
{

	for (int i = 1; i < n; i++) {

		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	printf("\n Sorted Array by Insertion: \n");
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
		int arrinsert[5000];
		
		srand(time(NULL));
		for (int i = 0; i < n; i++)
		{
			arr[i] = rand() % 100;	
			arrinsert[i] = arr[i];
			
		}
		insertionSort(arr, n);

		

}
