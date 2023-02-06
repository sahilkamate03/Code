#include <bits/stdc++.h>
using namespace std;

int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int b; cin >> b;
	int key_size; cin>> key_size;
	int drive_size; cin>> drive_size;

	int k[key_size];
	for (int i =0; i<key_size; i++) cin>> k[i];

	int d[drive_size];
	for (int i =0; i<drive_size; i++) cin>> d[i];

	int ans = 0;
	int sum;
	for (int i=0; i<key_size; i++){
		for (int j=0; j<drive_size; j++){
			sum = k[i] + d[j];
			if (sum > b) break;
			if (sum>ans) ans = sum;
		}
	}

	(ans!=0) ? cout<<ans : cout << -1;
}
