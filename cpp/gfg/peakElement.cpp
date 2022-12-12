#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{
   // Your code here
   for (int i=1; i<n; i++){
		if (i==n && arr[i-1]<arr[i]) cout << "1st "<<i;
		if (i<=n && arr[i-1]<arr[i] && arr[i]>arr[i+1]) cout << "2nd " << i;

   }
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n=3;
	int arr[n] ={1,2,5};
	peakElement(arr, n);
}
