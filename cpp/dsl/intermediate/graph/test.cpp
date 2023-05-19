#include <bits/stdc++.h>
using namespace std;

	int comparator(const void * p1, const void* p2)
{
    const int(*x)[3] = p1;
    const int(*y)[3] = p2;
 
    return (*x)[2] - (*y)[2];
}

int main()
{
	int edge[5][3] = { { 0, 1, 10 },
                       { 0, 2, 6 },
                       { 0, 3, 5 },
                       { 1, 3, 15 },
                       { 2, 3, 4 } };
    qsort(edge, 5, sizeof(edge[0]), comparator);

    for (int i=0; i<5; i++)
    {
    	for (int j=0; j<3; j++)
    	{
    		cout << edge[i][j] << " ";
    	}
    	cout << endl;
    }
	return 0;
}