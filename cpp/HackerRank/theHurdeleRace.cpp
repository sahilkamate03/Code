#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n,k;
	cin >> n >> k;

	int arr[n];
	int x = k;

	for (int i=0; i<n; i++){
		cin >> arr[i];
		if (arr[i] > x) x=arr[i];
	}

	if (k==x) cout<< 0 <<endl;
	else cout<< x-k << endl;

}
