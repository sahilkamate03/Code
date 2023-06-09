#include <bits/stdc++.h>
using namespace std;

int na(int n)
{
	if (n==0)
		return 0;

	return na(n-1) +n;
}

int main()
{
	cout << na(10) << endl;
}
