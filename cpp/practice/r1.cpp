#include <bits/stdc++.h>
using namespace std;

int dTh(int number)
{
	if (number==0)
		return 0;
	
	return dTh (number/2)*10 +number%2;
}

int main()
{
	cout << dTh(5) << endl;
}
