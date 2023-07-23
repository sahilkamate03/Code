#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t; cin >>t;
	while (t--)
	{
		int n, m;
		cin >> n >>m;
		map<int, int> mp;
		string ans ="YES";
		bool go =false;

		for (int i=0; i<m; i++)
		{
			int a, b, d;
			cin >> a >> b >>d;

			if (go)
				continue;

			if (mp.find(a) != mp.end() && mp.find(b) != mp.end() && abs(mp[a] -mp[b]) != abs(d))
			{
				cout << a << " " << b;
				ans = "NO";
				go =true;
			} 
			else if (mp[a])
			{
				mp[b] =mp[a] +d;
			}
			else if (mp[b])
			{
				mp[a] =mp[b] -d;
			}
			else 
			{
				mp[a] =0;
				mp[b] =d;
			}
		}

		cout << ans << endl;
	}
}
