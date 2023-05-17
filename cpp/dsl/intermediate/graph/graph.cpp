#include <bits/stdc++.h>
using namespace std;

#define GRAPH_SIZE 100

class Graph
{
private:
	vector<int> adjList[GRAPH_SIZE];
	bool isInitialized;

public:
	Graph (): isInitialized{false} {}

	void addNode(int, int);
	void remove(int, int);
	void printNode();
	void bfs();
	void dfs();
};

void Graph::addNode(int u, int v)
{
	if (u>=GRAPH_SIZE || v>=GRAPH_SIZE)
	{
		cout << "Enter element less than "<< GRAPH_SIZE << endl;
		return;
	}

	if (!isInitialized)
		isInitialized =!isInitialized;

	adjList[u].push_back(v);
	adjList[v].push_back(u);
}

void Graph::printNode()
{
	if (!isInitialized)
	{
		cout << "Graph is empty.\n";
		return;
	}

	for (int i=0; i<GRAPH_SIZE; i++)
	{
		if (!adjList[i].size())
			continue;
		cout << i << ": ";
		for (int j=0; j<adjList[i].size(); j++)
			cout << adjList[i][j] << " ";
		cout << endl;
	}
}

void Graph::remove(int s, int d)
{
	auto it =find(adjList[s].begin(),adjList[s].end(), d);
	if (it==adjList[s].end())
	{
		cout << "Edge Not Present.\n";
		return;
	}

	for (int i=0; i<adjList[s].size();i++)
	{
		if (adjList[s][i]==d)
			swap(adjList[s][i], adjList[s][adjList[s].size()-1]),
			adjList[s].pop_back();
	}


	for (int i=0; i<adjList[d].size();i++)
	{
		if (adjList[d][i]==s)
			swap(adjList[d][i], adjList[d][adjList[d].size()-1]),
			adjList[d].pop_back();
	}

	cout << "Edge Removed Succesfully!.\n";
}

void Graph::bfs()
{
	if (!isInitialized)
	{
		cout << "Graph is empty.\n";
		return;
	}

	queue<int> q;
	int vertex1 =0;
	for (int i=0; i<GRAPH_SIZE; i++)
	{
		if (adjList[i].empty())
			continue;
		vertex1 =i;
		break;
	}

	bool visitedNodes[GRAPH_SIZE] ={false};
	q.push(vertex1);

	while(!q.empty())
	{
		int temp =q.front();
		visitedNodes[temp] =true;
		for (int i=0; i<adjList[temp].size(); i++)
		{
			if (visitedNodes[adjList[temp][i]]==true)
				continue;
			visitedNodes[adjList[temp][i]] =true;
			q.push(adjList[temp][i]);
		}
		q.pop();
		cout << temp << " ";
	}
	cout << endl;
}

void Graph::dfs()
{
	if (!isInitialized)
	{
		cout << "Graph is empty.\n";
		return;
	}

	stack<int> st;
	int vertex1 =0;
	for (int i=0; i<GRAPH_SIZE; i++)
	{
		if (adjList[i].empty())
			continue;
		vertex1 =i;
		break;
	}

	bool visitedNodes[GRAPH_SIZE] ={false};
	st.push(vertex1);

	while(!st.empty())
	{
		int temp =st.top();
		st.pop();
		visitedNodes[temp] =true;
		for (int i=0; i<adjList[temp].size(); i++)
		{
			if (visitedNodes[adjList[temp][i]]==true)
				continue;
			visitedNodes[adjList[temp][i]] =true;
			st.push(adjList[temp][i]);
		}
		cout << temp << " ";
	}
	cout << endl;	
}

int main()
{
	Graph graph;

	graph.addNode(100,2);
	graph.addNode(1,3);
	graph.addNode(2,4);
	graph.addNode(2,5);
	graph.addNode(2,3);
	graph.addNode(3,5);
	graph.addNode(4,5);

	graph.printNode();
	graph.bfs();
	graph.dfs();

	graph.remove(1,2);
	graph.remove(1,2);

	graph.printNode();

	return 0;
}