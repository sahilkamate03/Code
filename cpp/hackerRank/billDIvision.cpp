#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, k;
	cin >>n >>k;
	int x;
	int correct_sum = 0;
	for (int i=0; i<n; i++) {
		cin>>x;
		if(i!=k) correct_sum+=x;
	}

	int sum;
	cin >>sum;

	if (sum == correct_sum/2) cout << "Bon Appetit" << endl;
	else cout << sum - correct_sum/2 << endl;

}
