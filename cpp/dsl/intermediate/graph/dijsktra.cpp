#include <bits/stdc++.h>
using namespace std;

#define V 9

int minSet(int key[], int visitedNodes[])
{
	int minIndex, minN =INT_MAX;
	for (int i=0; i<V; i++)
	{
		if (!visitedNodes[i] && key[i] <= minN)
		{
			minN =key[i];
			minIndex =i;
		}
	}

	return minIndex;
}

void printPath(int parent[], int i)
{
	if (parent[i]==-1)
	{
		
		return;
	}

	printPath(parent, parent[i]);
	cout << parent[i] << " -> ";

}

void dijsktraAlgo(int graph[][V])
{
	int key[V];
	int visitedNodes[V];
	int parent[V];

	for (int i=0; i<V; i++)
		key[i] =INT_MAX, visitedNodes[i] =false;

	key[0] =0;
	parent[0] =-1;

	for (int v =0; v <V; v++)
	{
		int u =minSet(key, visitedNodes);
		visitedNodes[u] =true;

		for (int i=0; i< V; i++)
		{
			if (!visitedNodes[i] && graph[u][i] && key[u] != INT_MAX && key[u] +graph[u][i] < key[i])
			{
				key[i] =key[u] +graph[u][i];
				parent[i] =u;
			} 
		}
	}

	for (int i=0; i<V; i++)
	{
		cout << i << " : " << key[i] << endl;
		cout << "Path: ";
		printPath(parent, i);
		cout << i << endl;
	}

	return;
}

int main()
{
	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
						{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
						{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
						{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
						{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
						{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
						{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
						{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
						{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
	dijsktraAlgo(graph);
	return 0;
}