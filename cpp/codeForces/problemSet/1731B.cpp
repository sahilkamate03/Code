#include <bits/stdc++.h>
using namespace std;

#define int long long int

int getSum(int n)
{
	int sum(0);
	sum += (n *(n+1) *(2*n +1)) / 6;
	n--;
	sum += (n *(n+1) *(n+2))/3;
	return sum;
}


int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int t(0); cin>>t;
	while (t--)
	{
		int n(0); cin>>n;
		int sum(getSum(n));
		sum %=(int)(10e9 +7);
		sum *=2022;
		cout <<sum << "\n";
	}
}
