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
		string ans = "NO";
		int x, y;
		cin >> x>>y;
		if (x==y) ans ="YES";
		if (y-x >= x) ans="YES";
		cout << ans << endl;
	}
}
