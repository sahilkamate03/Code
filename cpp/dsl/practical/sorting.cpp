#include <bits/stdc++.h>
using namespace std;

//first find the smallest fibo number than size of the array

int fibonacciSearch(int arr[], int size, int key)
{
	int fib1 =0, fib =1;
	int offset =0;
	while (fib<size)
	{
		fib +=fib1; fib1 =fib-fib1;
	}

	int fib2 =fib -fib1;

	// cout << fib2 << " " << fib1 << " " << fib << endl;

	while (fib > 1)
	{
		int i= min(offset +fib2,size -1);
		cout << fib2 << " " << fib1 << " " << fib << " " << offset << " " << i << " " << arr[i] << endl;
		if (arr[i] <key)
		{
			fib =fib1;
			fib1 =fib2;
			fib2 =fib -fib1;
			offset =i;
		}

		else if (arr[i] >key)
		{
			fib =fib2;
			fib1 =fib1 -fib2;
			fib2 =fib -fib1;
		}

		else 
			return i;
	}

	if (fib == 1 && arr[offset + 1] != key) 
	{
  		return -1;
  	}
	return -1;
}

int main()
{
	int size =11;
	int arr[size] ={10, 12, 35, 40, 45, 50, 80, 82, 85, 90, 100};
	int key =85;

	cout << fibonacciSearch(arr, size, key);

}