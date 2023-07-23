#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin>>n;
	if (n & 1 || n==2)
		cout << "NO" << endl;
	else cout << "YES" << endl;

}
