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
	   int y, x;
	   cin >>x >>y;
	   cout << (x/y) + (x%y) << endl;
	}
}
