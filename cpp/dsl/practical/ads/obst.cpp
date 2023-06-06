#include <bits/stdc++.h>
using namespace std;
#define MAX 50

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int key)
	{
		data =key;
		left =nullptr;
		right =nullptr;
	}
};

Node* construct(int r[][MAX], int i, int j)
{
	if(!r[i][j])	return nullptr;
	Node *root =new Node(r[i][j]);
	root->left =construct(r, i, r[i][j] -1);
	root->right =construct(r,r[i][j]+1 ,j);
	return root;
}

Node* obst(int p[], int q[], int n)
{
	int c[MAX][MAX], w[MAX][MAX], r[MAX][MAX];

	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=n; j++)
			c[i][j] =w[i][j] =r[i][j] =0;
	}

	for (int i=1; i<=n; i++)
	{
		w[i][i] = q[i-1] +p[i] + q[i];
		c[i][i] =w[i][i];
		r[i][i] =i;
	}

	for (int s =2; s<=n; s++)
	{
		for (int i=1; i+s-1 <=n; i++)
		{
			int j=i+s-1;
			w[i][j] =w[i][j-1] +p[j] +q[j];
			c[i][j] =INT_MAX;
			for (int k =i; k<=j; k++)
			{
				int cost =w[i][j] +c[i][k-1] +c[k+1][j];
				if (cost < c[i][j])
				{
					c[i][j] =cost;
					r[i][j] =k;
				}
			}
		}
	}

	return construct(r,1,n);
}

void inorder(string arr[], Node* node)
{
	if (!node) return;
	inorder(arr, node->left);
	cout << arr[node->data -1] << " ";
	inorder(arr, node->right);
}

int main()
{
	string arr[] ={"do", "if", "read", "while"};
	int p[] ={1, 3, 1, 3};
	int q[] ={1,2,1,1,3};

	int n=sizeof(q)/sizeof(int);

	Node* root =obst(p, q, n-1);
	inorder(arr, root);
}
