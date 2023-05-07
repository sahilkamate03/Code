#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
	return (a[0] < b[0]);
}

int main()
{
	vector<vector<int>> v;
	vector<int> temp;

	// [[1,3],[2,6],[8,10],[15,18]]

	temp.clear();
	temp.push_back(15);
	temp.push_back(18);
	v.push_back(temp);

	temp.clear();
	temp.push_back(1);
	temp.push_back(3);
	v.push_back(temp);

	temp.clear();
	temp.push_back(2);
	temp.push_back(6);
	v.push_back(temp);

	temp.clear();
	temp.push_back(8);
	temp.push_back(10);
	v.push_back(temp);

	

	for (int i=0; i<v.size(); i++)
	{
		cout << v[i][0] << " " << v[i][1] << endl;
	}

	sort(v.begin(), v.end(), compare);

	for (int i=0; i<v.size(); i++)
	{
		cout << v[i][0] << " " << v[i][1] << endl;
	}
	return 0;
}