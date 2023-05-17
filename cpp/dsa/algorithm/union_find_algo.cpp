#include <bits/stdc++.h>
using namespace std;
#define SIZE 50

int arr[SIZE];
int rank[SIZE] ={0};

void inititalize()
{
	for (int i=0; i<SIZE; i++)
		arr[i] =i;
}

int findNumber(int x)
{
	if (arr[x]==x)
		return x;
	return findNumber(arr[x]);
}

void unionSet(int a, int b)
{
	int x =findNumber(a);
	int y =findNumber(b);

	if (x == y)
		return;

	arr[y] =x;
	rank[y]++;
}

int main()
{
	inititalize();
	cout << findNumber(9) << endl;
	unionSet(9,0);
	cout << findNumber(9) << endl;
	return 0;
}