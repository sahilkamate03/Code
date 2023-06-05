#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	bool lflag;
	bool rflag;

	Node(int key)
	{
		data =key;
		left =nullptr;
		right =nullptr;
		lflag =1;
		rflag =1;
	}
	
	friend class TBT;
};

class TBT
{
public:
	Node* dummyNode;
	Node* root;
	TBT()
	{
		dummyNode = new Node(-1);
		dummyNode->right =dummyNode;
		dummyNode->left =dummyNode;
		
		root =nullptr;
	}

	void insert(int);
};

void TBT::insert(int key)
{
	Node* newNode =new Node(key);

	if (!root)
	{
		root =newNode;
		dummyNode->left =root;
		dummyNode->lflag =0;
		root->left =dummyNode;
		root->right =dummyNode;
		return;		
	}

	Node* node =root;
	while (true)
	{
		if (key < node->data)
		{
			if (node->lflag)
			{
				newNode->left =node->left;
				newNode->right =node;
				node->left =newNode;
				node->lflag =0;
				break;
			}
			node =node->left;
		}
		else if(key >=node->data)
		{
			if (node->rflag)
			{
				newNode->right =node->right;
				newNode->left =node;
				node->right =newNode;
				node->rflag =0;
				break;
			}
			node =node->right;
		}
	}
	return;
}

void inorder(Node* node)
{
	if (!node->lflag)
	{
		inorder(node->left);
	}
	cout << node->data << " "; 

	if (!node->rflag)
	{
		inorder(node->right);
	}
}

int main()
{
	TBT tbt;

	tbt.insert(60);
	tbt.insert(40);
	tbt.insert(70);
	tbt.insert(90);
	tbt.insert(20);
	tbt.insert(30);
	tbt.insert(7);
	
	inorder(tbt.root);
	cout << endl;
}
