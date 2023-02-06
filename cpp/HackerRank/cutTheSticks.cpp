#include <bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int n; cin>> n;
	int arr[n];
	for (int i=0; i< n; i++) cin>>arr[i];
	sort(arr,arr+n,greater<int>());
	
	int short_no ;
	for (int i=0; i<n; i++){
		if (arr[n-i-1] !=0)  {short_no = arr[n-i-1]; break;}
	}

	while (arr[0]!=0){
		int i =0;
		for (; i<n; i++){
			if (arr[i] == 0) break;
			arr[i] -= short_no;
		}
		cout << i << endl;
		for (int i=0; i<n; i++){
			if (arr[n-i-1] !=0)  {short_no = arr[n-i-1]; break;}
		}
	}
}
