#include <bits/stdc++.h>
using namespace std;

double power(float x, long long int n)
{
	if (n==1)
		return x;
	double s =power(x, n/2);
	if (n&1)
		return s*s*x;
	else return s*s;
}


int main()
{
	float x; long long int n;
	cin >> x>> n;
	if (n==0)
		cout << 1 << endl;
	else if (n<0)
		cout << 1/power(x, n) << endl;
	else 
		cout << power(x,n) << endl;
	return 0;
}