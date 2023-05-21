#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
	int* parent;
	int* rank;

public:
	DSU(int n)
	{
		parent = new int[n];
		rank = new int[n];

		for (int i = 0; i < n; i++)
			parent[i] = -1,
			            rank[i] = 1;
	}

	int findNumber(int);
	void unionSet(int, int);

	friend class Graph;

	~DSU()
	{
		delete[] parent;
		delete[] rank;
	}
};

int DSU::findNumber(int value)
{
	while (parent[value] != -1)
	{
		parent[value] = parent[parent[value]];
	}
	return value;
}

void DSU::unionSet(int a, int b)
{
	int x = findNumber(a);
	int y = findNumber(b);

	if (x == y)
		return;

	if (rank[x] < rank[y])
		parent[y] = x;
	else if (rank[x] > rank[y])
		parent[x] = y;
	else
		parent[x] = y;
	rank[y]++;
}

class Graph
{
private:
	vector<vector<int>> edgeList;
	int V;

public:
	Graph(int V) {this->V;}

	void addNode (int, int, int);
	void kruskalAlgo ();
};

void Graph::addNode(int w, int x, int y)
{
	edgeList.push_back({w, x, y});
}

void Graph::kruskalAlgo()
{
	sort(edgeList.begin(), edgeList.end());
	DSU dsu(V);
	
	int mstCost = 0;
	for (int i = 0; i < edgeList.size() - 1; i++)
	{
		int x = dsu.findNumber(edgeList[i][1]);
		int y = dsu.findNumber(edgeList[i][2]);

		if (x == y)
			continue;

		dsu.unionSet(x, y);
		mstCost += edgeList[i][0];
	}

	cout << "Cost: " << mstCost << endl;
	return;
}

int main()
{
	Graph graph(10);
	graph.addNode(4, 3, 5);
	graph.addNode(3, 1, 3);
	graph.addNode(6, 2, 3);
	graph.addNode(7, 1, 2);
	graph.addNode(1, 4, 3);

	graph.kruskalAlgo();

	return 0;
}