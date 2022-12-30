#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(int arr[], int size, int k)
{
	int start =0, end =0, sum =arr[0];
	while (start < size)
	{
		if (sum < k ) start++, sum+=arr[start];
    	else if (sum > k && end < start) sum-=arr[end], end++;
    	else if (sum > k && end == start) sum=arr[++start], end++;
		else{
			 cout << ++end << " : " << ++start << endl; 
			 break;
		}
	}
}

int32_t main(){
	int size =5;
	int arr[size] = {1,2,3,7,5};
	int k=12;
	solve(arr, size, k);
}


































// ------------------------------------------------ Failed Attempt 1 --------------------------------------------------------

// void print(int arr[], int size)
// {
// 	for (int i=0; i<size; i++) 
// 		cout << arr[i] << " ";
// 	cout << endl;
// }

// void solve(int arr[], int size, int req)
// {
// 	int prefixSum[size];
// 	prefixSum[0] =arr[0];

// 	for (int i=1; i<size; i++)
// 	{
// 		prefixSum[i] = prefixSum[i-1]+arr[i];
// 		if (prefixSum[i]==req)
// 			return {1, ++i};
		
// 	}

// 	//
// 	print(prefixSum, size);

// 	int n=1, temp=0;

// 	while(n<=size)
// 	{
// 		int checker =prefixSum[n] - prefixSum[temp];

// 		if (checker<req)
// 			n++;

// 		else if (checker>req)
// 			temp++, n=temp+1;

// 		else
// 			return {temp+2,++n}; 

// 	}

// 	return {-1};
    
// }

// int main(){

// 	// #ifndef ONLINE_JUDGE
// 	// freopen("input.txt", "r", stdin);
// 	// freopen("output.txt", "w", stdout);
// 	// #endif
	
// 	int size =5;
// 	 // cin>> size;
// 	int req =12; 
// 	// cin >> req;
// 	int arr[size] ={1,2,3,7,5};

// 	// for (int i=0; i<size; i++)	
// 		// cin >> arr[i];

// 	solve(arr, size, req);
	
// }
