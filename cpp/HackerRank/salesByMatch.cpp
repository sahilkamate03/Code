#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n; cin>>n;
	int arr[101]={0};
	for (int i=0; i<n; i++)
	{
		int x; cin>>x;
		arr[x]++;
	}

	int ans=0;

	for (int i=0; i<101; i++)
		ans+=arr[i]/2;

	cout << ans << endl;
}
