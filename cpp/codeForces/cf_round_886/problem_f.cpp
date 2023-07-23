#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;

	while(t--)
	{
		int n; cin >>n;
		vector<int> count (n+1, 0); vector<int> m(n+1, 0);
		for (int i=0; i<n; i++)
		{
			int x; cin >>x;
			if (x<=n)
				count[x]++;
		}

		for (int i=1; i<=n; i++)
			for (int j=i; j<=n; j+=i) 
				m[j] +=count[i];
			

		cout << *max_element(m.begin(), m.end()) << endl;
			
	}
}
