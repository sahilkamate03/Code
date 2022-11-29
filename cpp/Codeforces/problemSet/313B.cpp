#include <bits/stdc++.h>
using namespace std;

int answer(string s,int l, int r)
{
	cout << s << endl;
	return l+r;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s; cin >>s;
	int q; cin >>q;

	while(q--) 
	{
		int l, r;
		cin >> l>>r;
		cout << answer(s,l,r) << endl;
	}
}
