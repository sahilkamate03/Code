#include <bits/stdc++.h>
using namespace std;

#define GRAPH_SIZE 100

class Graph
{
private:
	vector<int> adjList[GRAPH_SIZE];
	int arr[GRAPH_SIZE];
	bool isInitialized;

public:
	Graph (): isInitialized{false}
	{
		for (int i = 0; i < GRAPH_SIZE; i++)
			arr[i] = i;
	}

	void addNode(int, int);
	void remove(int, int);
	void printNode();
	void bfs();
	void dfs();
	int findNumber(int);
	bool unionSet(int, int);
	bool isConnected();
};

void Graph::addNode(int u, int v)
{
	if (u >= GRAPH_SIZE || v >= GRAPH_SIZE)
	{
		cout << "Enter element less than " << GRAPH_SIZE << endl;
		return;
	}

	if (!isInitialized)
		isInitialized = !isInitialized;

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

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		if (!adjList[i].size())
			continue;
		cout << i << ": ";
		for (int j = 0; j < adjList[i].size(); j++)
			cout << adjList[i][j] << " ";
		cout << endl;
	}
}

void Graph::remove(int s, int d)
{
	auto it = find(adjList[s].begin(), adjList[s].end(), d);
	if (it == adjList[s].end())
	{
		cout << "Edge Not Present.\n";
		return;
	}

	for (int i = 0; i < adjList[s].size(); i++)
	{
		if (adjList[s][i] == d)
			swap(adjList[s][i], adjList[s][adjList[s].size() - 1]),
			     adjList[s].pop_back();
	}


	for (int i = 0; i < adjList[d].size(); i++)
	{
		if (adjList[d][i] == s)
			swap(adjList[d][i], adjList[d][adjList[d].size() - 1]),
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
	int vertex1 = 0;
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		if (adjList[i].empty())
			continue;
		vertex1 = i;
		break;
	}

	bool visitedNodes[GRAPH_SIZE] = {false};
	q.push(vertex1);

	while (!q.empty())
	{
		int temp = q.front();
		visitedNodes[temp] = true;
		for (int i = 0; i < adjList[temp].size(); i++)
		{
			if (visitedNodes[adjList[temp][i]] == true)
				continue;
			visitedNodes[adjList[temp][i]] = true;
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
	int vertex1 = 0;
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		if (adjList[i].empty())
			continue;
		vertex1 = i;
		break;
	}

	bool visitedNodes[GRAPH_SIZE] = {false};
	st.push(vertex1);

	while (!st.empty())
	{
		int temp = st.top();
		st.pop();
		visitedNodes[temp] = true;
		for (int i = 0; i < adjList[temp].size(); i++)
		{
			if (visitedNodes[adjList[temp][i]] == true)
				continue;
			visitedNodes[adjList[temp][i]] = true;
			st.push(adjList[temp][i]);
		}
		cout << temp << " ";
	}
	cout << endl;
}

int Graph::findNumber(int x)
{
	if (arr[x] == x)
		return x;
	return findNumber(arr[x]);
}

bool Graph::unionSet(int a, int b)
{
	int x = findNumber(a);
	int y = findNumber(b);

	if (x == y)
		return false;

	arr[y] = x;
	return true;
}

bool Graph::isConnected()
{
	int numVertices = GRAPH_SIZE;

	int vertex1 = 0;
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		if (adjList[i].empty())
			continue;
		vertex1 = i;
		break;
	}

    for (int i = vertex1; i < GRAPH_SIZE; i++)
    {
        if (!adjList[i].empty())
        {
            int root1 = findNumber(i);
            for (int j = 0; j < adjList[i].size(); j++)
            {
            	cout << i << " " << adjList[i][j] << endl;
                int root2 = findNumber(adjList[i][j]);
                if (root1 != root2)
                    unionSet(root1, root2);
            }
        }
    }

    int root = findNumber(vertex1);
    for (int i = vertex1; i < GRAPH_SIZE; i++)
    {
        if (!adjList[i].empty())
        {
            for (int j = 0; j < adjList[i].size(); j++)
            {
                int root1 = findNumber(adjList[i][j]);
                if (root != root1)
                    return false;
            }
        }
    }

    return true;
}

void menu(Graph &graph)
{
	cout << "\n1. Add Node\n2. Print Adjacent List\n3. BFS\n4. DFS\n5. Delete\n6. Check Connected\n7. Exit\n";
	cout << "Enter choice: ";
	int choice; cin >> choice;
	int x, y;

	cout << "\n";

	switch (choice)
	{
	case 1:
		cout << "Enter Two Node: ";
		cin >> x >> y;
		graph.addNode(x, y);
		break;
	case 2:
		cout << "\nAdjacent List:\n";
		graph.printNode();
		break;
	case 3:
		cout << "BFS: \n";
		graph.bfs();
		break;
	case 4:
		cout << "DFS: \n";
		graph.dfs();
		break;
	case 5:
		cout << "Enter Edge Nodes: ";
		cin >> x >> y;
		graph.remove(x, y);
		break;
	case 6:
		if (graph.isConnected())
			cout << "Graph is Connected.\n";
		else
			cout << "Graph is not Connected.\n";
		break;
	default:
		exit(0);
	}
}

int main()
{
	cout << "\nGraph\n";

	Graph graph;
	while (true)
		menu(graph);

	return 0;
}
