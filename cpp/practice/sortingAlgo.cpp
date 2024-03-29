#include <bits/stdc++.h>
using namespace std;

void printArray (int arr[], int n)
{
	for (int i=0; i<n; i++) cout << arr[i] << " ";
}

void bubbleSort(int arr[], int n)
{
	for (int i=1; i<n; i++)
	{
		int start =i, swapCount =0;
		for (int j=start; j<n; j++)
		{
			if (arr[j-1] > arr[j]) swapCount++, swap(arr[j-1], arr[j]); 
		}
		
		if (swapCount == 0) break;
	}
}

void selectionSort(int arr[], int n)
{
	for (int i =0; i<n; i++)
	{
		int minElement = arr[i], minElementIndex =i;
		for (int j=i+1; j<n; j++)
		{
			if (arr[j] < minElement) minElementIndex =j, minElement = min(minElement, arr[j]);
		}
		
		swap(arr[i], arr[minElementIndex]);
	}
}

void insertionSort(int arr[], int n)
{
	for (int i=1; i<n; i++)
	{
		int start =i, swapCount =0;
		while (arr[start-1] > arr[start] && start!=0)
		{
			swap(arr[start-1], arr[start]);
			start--;
		}

	}
}

int main()
{
	int n =5;
	int arr[n] = {3, 6, 6, 2, 5};
	
	//bubbleSort(arr, n);
	//selectionSort(arr, n);
	insertionSort(arr ,n);
	printArray(arr, n);
}
