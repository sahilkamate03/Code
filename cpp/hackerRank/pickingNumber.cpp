#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin>>n;
	int arr[101]= {0};
	int x;
	int max =0, ans =1;
	for (int i=0; i<n; i++) {
		cin>>x;
		arr[x]++;
		if (x>max) max = x;
	}

	// for (int i=0; i<=max; i++) cout << arr[i] << " ";
	int most=0;
	for (int i=0; i<= max; i++ ){
		if (arr[i] > most) most = arr[i], cout<<most << " ";
		if (arr[i]==0) continue;
		if (arr[i+1] == 0) continue;
		if (arr[i]+arr[i+1]> ans) ans = arr[i] + arr[i+1];
	}

	(ans!=1 && ans>most) ? cout << ans : cout << most;
}
