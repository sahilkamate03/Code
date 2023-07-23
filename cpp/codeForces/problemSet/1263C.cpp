#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int i =2;
		while(n/i -3)
		{
			cout << n/i << " " << n-(n/i)*i << endl;
			i++;
		}
	}
}
