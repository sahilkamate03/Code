#include <bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n , k;
	cin >>n >>k;
	unordered_map <int, int> map;

	for (int i=0; i<n; i++)
	{
		int x; 
		cin >>x; 
		map[x]++;
	}

	for (auto i : map)
		cout << i.first << " " << i.second << endl;

}
