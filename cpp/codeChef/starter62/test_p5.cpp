#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--){
		int x, y;
		cin >> x>> y;
		string ans = "YES";
		if (x*2 > y) ans = "NO";
		cout << ans << endl;
	}
}

