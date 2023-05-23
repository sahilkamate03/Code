#include <bits/stdc++.h>
using namespace std;

#define V 5

void printMST(int mst[], int graph[V][V])
{
	for (int i=1; i<V; i++)
	{
		cout << mst[i] << " -> " << i << "\t";
		cout << graph[i][mst[i]] << endl;
	}
}


int minKey(int key[], bool visitedNodes[])
{
	int minAns = INT_MAX, minIndex;

	for (int i = 0; i < V; i++)
	{
		if (visitedNodes[i] == false && key[i] < minAns)
		{
			minAns = key[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void primsAlgo(int graph[V][V])
{
	int mst[V];
	int key[V];
	bool visitedNodes[V];

	for (int i=0 ;i<V; i++)
		key[i] =INT_MAX, visitedNodes[i] =false;
	// int vertex1 = -1;
	// for (int i = 0; i < V; i++)
	// {
	// 	if (vertex1 != -1)
	// 		break;

	// 	for (int j = 0; j < V; j++)
	// 	{
	// 		if (graph[i][j] == 0)
	// 			continue;

	// 		vertex1 = i;
	// 		break;
	// 	}
	// }

	key[0] = 0;
	mst[0] = -1;
	// cout << vertex1 << endl; checkpoint find vertex

	for (int count = 0; count < V - 1; ++count)
	{
		int u = minKey(key, visitedNodes);
		visitedNodes[u] = true;
		for (int v = 0; v < V; ++v)
		{
			if (visitedNodes[v] == false && graph[u][v] && graph[u][v] < key[v])
			{
				mst[v] = u;
				key[v] = graph[u][v];
			}
		}
	}

	printMST(mst, graph);

}


int main()
{
	int graph[V][V] ={ { 0, 2, 0, 0, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 0, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

	
	// cout << "Enter no of nodes: ";
	// int n; cin>> n;


	primsAlgo(graph);

	return 0;
}