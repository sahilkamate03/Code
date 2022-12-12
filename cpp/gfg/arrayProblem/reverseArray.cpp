#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin>>n;
	int arr[n];

	for (int i=0; i<n; i++)
		cin >> arr[i];

	int left=0, index=0, right=n-1;

	while (index <= right)
	{	
		if (arr[index] == 0)
			swap(arr[index], arr[left]), index++, left++;

		else if (arr[index] == 1)
			index++;

		else if (arr[index]==2)
			swap(arr[index], arr[right]), right--;
	}

	print(arr, n);
}
