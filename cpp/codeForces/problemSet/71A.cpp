#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >>n;
	while(n--)
	{
		string s;
		cin >> s;
		string ans;
		ans =s;
		if (s.size()>10)
		{
			ans =s[0] + to_string(s.size()-2) + s[s.size()-1];
		}
		cout << ans << endl;
	}
}
