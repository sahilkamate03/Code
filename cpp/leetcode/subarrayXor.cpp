#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> v ={4,2,2,6,4};
	int x =0;
	for (int i=0; i<v.size(); i++)
	{
		x ^=v[i];
		cout << x << " ";
	}
	cout << endl;
	x=0;
	for (int i=0; i<v.size(); i++)
	{
		x ^=(v[i]);
		int y=x^6;
		cout << y << " ";
	}
	cout << endl;
	
	return 0;
}