#include <bits/stdc++.h>
using namespace std;

#define n 500

int arr[n];

void initialize()
{
	for (int i=0; i<n; i++)
		arr[i] =i;
}

int findNumber(int a)
{
	if (arr[a]!=a)
		return findNumber(arr[a]);
	return a;
}

bool unionNumber(int a, int b)
{
	int x =findNumber(a);
	int y =findNumber(b);

	if (x==y)
		return true;

	arr[x] =y;
	return false;
}

void kruskalAlgo(vector<vector<int>> edgeList)
{
	sort(edgeList.begin(), edgeList.end());
	
	int cost =0;
	for (int i=0; i<edgeList.size(); i++)
	{
		if (!unionNumber(edgeList[i][1], edgeList[i][2]))
		{
			cout << edgeList[i][1] << " -> " << edgeList[i][2] << " : " <<  edgeList[i][0] << "\n";
			cost +=edgeList[i][0];
		}
	}

	cout << "Cost: " << cost << "\n";
}

int main()
{
	initialize();
	vector<vector<int>> edgeList;
	edgeList.push_back({4,0,1});
	edgeList.push_back({8,0,7});
	edgeList.push_back({8,1,7});
	edgeList.push_back({11,1,7});
	edgeList.push_back({2,2,8});
	edgeList.push_back({4,2,5});
	edgeList.push_back({7,2,3});
	edgeList.push_back({14,3,5});
	edgeList.push_back({9,3,4});
	edgeList.push_back({10,4,5});
	edgeList.push_back({2,6,5});
	edgeList.push_back({6,6,8});
	edgeList.push_back({1,6,7});
	edgeList.push_back({7,7,8});

	kruskalAlgo(edgeList);
}
