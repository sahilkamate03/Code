#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n=7;
	int ans=0;
	int i=0;
	while (n)
	{
		if (n%2)
			ans+=(pow(10,i)*1);
		else 
			ans+=0;
		n=n>>1;
		i++;
	}

	cout << ans << endl;
	return 0;
}