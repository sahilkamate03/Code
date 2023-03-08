#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;

	Node()
	{
		data =-1;
		left =NULL;
		right =NULL;
	}
};

struct BT
{
	Node* root;
	BT()
	{
		root =NULL;
	}
	
	Node* insert(Node*);
	void preOrder(Node*);
};

struct Node* BT::insert(Node* back=NULL)
{
	Node* newNode = new Node;
	
	int direction =-1;

	while(direction)
	{

		cout << "Enter data: "; cin>>newNode->data;
		cout << "1/2/3 == left/right/back: ";	
		cin >>direction;

		if (direction==1)
		{
			newNode->left =insert(newNode);	
		}
		else if(direction==2)
   		{
			newNode->right =insert(newNode);
		}
		else if (direction==3)
		{
			newNode =back;
			cout << "back!\n";
		}
		else 
		{
			return NULL;
		}
	}
}

void BT::preOrder(Node* root)
{
	if (root!=NULL)
	{
		cout << root->data;
		preOrder(root->left);
		preOrder(root->right);
	}
}
int main()
{
	BT bt1;

	bt1.insert();
	bt1.preOrder(bt1.root);
}
