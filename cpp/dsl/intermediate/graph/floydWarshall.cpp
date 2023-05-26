#include <bits/stdc++.h>
using namespace std;

#define nV 4

void floydWarshall(int graph[][nV])
{
	for (int k = 0; k < nV; k++)
	{
		for (int i = 0; i < nV; i++)
		{
			for (int j = 0; j < nV; j++)
			{
				if (graph[i][k] == INT_MAX || graph[k][j] == INT_MAX)
					continue;

				else
					graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}

	for (int i = 0; i < nV; i++)
	{
		for (int j = 0; j < nV; j++)
		{
			if (graph[i][j] == INT_MAX)
			{
				cout << "I" << " ";
				continue;
			}
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int graph[nV][nV] = {{ 0, 5, INT_MAX, 10 },
		{ INT_MAX, 0, 3, INT_MAX },
		{ INT_MAX, INT_MAX, 0, 1 },
		{ INT_MAX, INT_MAX, INT_MAX, 0 }
	};

	floydWarshall(graph);
	return 0;
}