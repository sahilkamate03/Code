

#include <bits/stdc++.h>
using namespace std;

int matrixSize =7;

class Topology
{
private:
    vector<vector<int>> matrix;
    vector<int> topoVector;

public:
    Topology()
    {
        for (int j=0; j<matrixSize; j++)
        {
            vector<int> temp;
            for (int i=0; i<matrixSize; i++)
                temp.push_back(0);
            matrix.push_back(temp);
        }
    
    }

    void insert(int source, int destination)
    {
        matrix[source][destination] =1;
    }

    void printMatrix()
    {
        for (int i=0; i<matrixSize; i++)
        {
            for (int j=0; j<matrixSize; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }

    void printTopo()
    {
        for (int i=0; i<matrixSize; i++)
        {
            int element =0;
            bool isScanReq =false;
            bool isWithoutParent =true;
            for (int j=0; j<matrixSize; j++)
            {
                if (matrix[i][j])
                {
                    isScanReq =true;
                    break;
                }
            }

            if (!isScanReq)
                continue;

            for (int j=0; j<matrixSize; j++)
            {
                if (matrix[j][i])
                {
                    isWithoutParent =false;
                    break;
                }
            }
            //cout << i << " " << isWithoutParent << endl;
            if (isWithoutParent)
                topoVector.push_back(i);
        }    
        
        stack<int> st;
        int visitedNodes[matrixSize] ={0};

        for (auto i:topoVector)
        {
            st.push(i);
        }

        while (!st.empty())
        {
            int temp =st.top();
            st.pop();
            cout << temp << " ";
            for (int i=0; i<matrixSize; i++)
            {
                if (!matrix[temp][i])
                    continue;

                if (visitedNodes[i])
                    continue;

                visitedNodes[i] =1;
                st.push(i);
            }
        }
    }

};

void menu(Topology &tp)
{
    cout << "\nMenu\n";
    cout << "1. Insert\n2. Multiple Insert\n3. Print Topo\n4. Exit\n";

    cout << "\nEnter Choice: ";
    int choice; cin>> choice;

    int n,x, y;
    switch(choice)
    {
    case 1:
        cout << "Enter the nodes (Directed Order): ";
        cin >> x >> y;
        tp.insert(x,y);
        break;

    case 2:
        cout << "Enter no of edges: ";
        cin >> n;
        for (int i=0; i<n; i++)
        {
            cout << i+1 << ". ";
            cin >> x >> y;
            tp.insert(x,y);
        }
        break;

    case 3:
        cout << "Topology: ";
        tp.printTopo();
        cout << endl;
        break;

    default:
        exit(0);
    }
}

int main()
{
    cout << "\nTopology Sort\n";

    Topology tp;
    while(true)
        menu(tp);
}
