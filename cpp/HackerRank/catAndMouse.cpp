#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int q; cin>>q;
	int x, y, z;
	for (int i=0; i<q; i++){
		cin >>x >>y >>z;
		if (abs(x-z) < abs(y-z))  cout << "Cat A" << endl;
		else if (abs(x-z) > abs(y-z)) cout << "Cat B" << endl;
		else cout << "Mouse C" << endl;
	}
}
