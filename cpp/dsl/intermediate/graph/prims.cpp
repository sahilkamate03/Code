#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
	vector<vector<int>> edgeList;
	int V;

public:
	Graph(int V) {this->V;}

	void addNode (int, int, int);
	void primsAlgo ();
};

void Graph::addNode(int w, int x, int y)
{
	edgeList.push_back({w, x, y});
}

void Graph::primsAlgo()
{
	int visitedNodes[V] ={0};
	sort(edgeList.begin(), edgeList.end());

	for (int i=0; i<edgeList.size(); i++)
	{
		cout << edgeList[i][0] << " " << edgeList[i][1] << " " << edgeList[i][2] << endl;
	}

	priority_queue<pair<int,int>> pq;
	pq.push({edgeList[0][1], edgeList[0][0]});

	return;
	while (!pq.empty())
	{



	}

}


int main()
{
	Graph graph(10);
	graph.addNode(4, 3, 5);
	graph.addNode(3, 1, 3);
	graph.addNode(6, 2, 3);
	graph.addNode(7, 1, 2);
	graph.addNode(1, 4, 3);

	graph.primsAlgo();

	return 0;
}