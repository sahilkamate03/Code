#include <bits/stdc++.h>
using namespace std;

#define n 9

int getMin(int key[], bool visitedNodes[])
{
	int minIndex =0;
	int minN =INT_MAX;

	for (int i=0; i<n; i++)
	{
		if (!visitedNodes[i] && key[i] < minN)
		{
			minN =key[i];
			minIndex =i;
		} 
	}	

	return minIndex;
}

void primsAlgo(int graph[][n])
{
	int mst[n];
	int key[n];
	bool visitedNodes[n];

	for (int i=0; i<n; i++)
		key[i] =INT_MAX, visitedNodes[i] =false;
	
	key[0] =0;

	for (int i=0; i<n; i++)
	{
		int s =getMin(key, visitedNodes);
		visitedNodes[s] =true;

		for (int j=0; j<n; j++)
		{
			if (!visitedNodes[j] && graph[s][j] && graph[s][j] < key[j])
			{
				key[j] =graph[s][j];
				mst[j] =s;
			}
		}
	}

	int cost =0;
	for (int i=1; i<n; i++)
	{
		cout << i << " -> " << mst[i] << " : " << key[i] << "\n"; 
		cost +=key[i];
	}
	cout << "Cost: " << cost << "\n";
}



int main()
{
	int graph[n][n] = {
	{0 ,4 ,0 ,0 ,0 ,0 ,0 ,8 ,0},
	{4 ,0 ,8 ,0 ,0 ,0 ,0 ,11,0},
	{0 ,8 ,0 ,7 ,0 ,4 ,0 ,0 ,2},
	{0 ,0 ,7 ,0 ,9 ,14,0 ,0 ,0},
	{0 ,0 ,0 ,9 ,0 ,10,0 ,0 ,0},
	{0 ,0 ,4 ,14,10,0 ,2 ,0 ,0},
	{0 ,0 ,0 ,0 ,0 ,2 ,0 ,1 ,6},
	{8 ,11,0 ,0 ,0 ,0 ,1 ,0 ,7},
	{0 ,0 ,2 ,0 ,0 ,0 ,6 ,7 ,0}
	};

	primsAlgo(graph);
}
