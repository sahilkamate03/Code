#include <bits/stdc++.h>
using namespace std;

int answer(string s,int l, int r)
{
	int ans =0;
	for (int i=l;i<r; i++)	
		if (s[i-1]==s[i]) ans++;
	
	return ans;
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
