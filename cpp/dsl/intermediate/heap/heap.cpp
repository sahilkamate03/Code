#include <bits/stdc++.h>
using namespace std;

void minHeapify(int arr[], int n, int i)
{
	int smallest =i;
	
	int l= 2*i+1;
	int r= 2*i+2;

	if (l<n && arr[l]<arr[smallest])
		smallest =l;

	if (r<n && arr[r]<arr[smallest])
		smallest =r;

	if (smallest!=i)
	{
		swap(arr[0], arr[smallest]);
		minHeapify(arr, n, smallest);
	}
	
}

void minHeap(int arr[], int n)
{
	for (int i=n/2-1; i>=0; i--)
		minHeapify(arr, n, i);
}

void maxHeapify(int arr[], int n, int i)
{
	int largest =i;

	int l= 2*i+1;
	int r= 2*i+2;

	if (l<n && arr[l] >arr[largest])
		largest =l;

	if (r<n && arr[r] >arr[largest])
		largest =r;

	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		maxHeapify(arr, n, largest);
	}

}

void maxHeap(int arr[], int n)
{
    for (int i=n/2-1; i>=0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
	for (int i=n/2-1; i>=0; i--)
		maxHeapify(arr, n, i);	

	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		maxHeapify(arr, i, 0);
	}
}

int n=0;
bool isInitialized=false;

void menu()
{
	cout << "\n1. Initialize\n2. Min Element\n3. Max Element\n4. Heap Sort\n5. Display\n6. Exit\n\n";

	cout << "Enter choice: ";
	int choice; cin >> choice;
	int *arr;

	switch(choice)
	{
	case 1:
		cout << "Total subjects: ";
		cin>> n;
		arr =new int[n];

		cout << "Enter marks: ";
		for (int i=0; i<n; i++)
			cin >>arr[i];
		isInitialized =true;
		break;
	
	case 2:
		if (!isInitialized)
		{
			cout << "First Initialize.\n";
			break;
		}
		minHeap(arr, n);
		cout << "Min Element: " << arr[0] << endl;
		break;

	case 3:
		if (!isInitialized)
		{
			cout << "First Initialize.\n";
			break;
		}
		maxHeap(arr, n);
		cout << "Max Element: " << arr[0] << endl;
		break;

	case 4:
		if (!isInitialized)
		{
			cout << "First Initialize.\n";
			break;
		}
		heapSort(arr, n);
		for (int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
		break;

	case 5:
		if (!isInitialized)
		{
			cout << "First Initialize.\n";
			break;
		}
		for (int i=0; i<n; i++)
			cout << arr[i] << " ";
		cout << endl;
		break;

	default:
		delete[] arr;
		exit(0);
	}

}

int main()
{
	cout << "\nHeap\n";
	while (1)
		menu();
}
