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
	void conversion();
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

vector<Node*> inorderVector;
void inorderMaker(Node* node)
{
	if (!node)
		return;
	inorder(node->left);
	inorderVector.push_back(node);
	inorder(node->right);
}

void TBT::conversion()
{
	if (!inorderVector.size())
	{
		cout << "BST not initialized." << endl;
		return;
	}
	for (int i = 2; i < inorderVector.size() - 1; i++)
	{
		Node *currentNode = inorderVector[i];
		if (currentNode->left)
			currentNode->lflag = 0;
		else
			currentNode->left = inorderVector[i - 1];

		if (currentNode->right)
			currentNode->rflag = 0;
		else
			currentNode->right = inorderVector[i + 1];
	}

	inorderVector[0]->left = dummyNode;
	inorderVector[inorderVector.size() - 1]->right = dummyNode;

	if (inorderVector.size() > 1)
	{
		if (inorderVector[0]->right)
			inorderVector[0]->rflag = 0;
		else
			inorderVector[0]->right = inorderVector[1];

		if (inorderVector[inorderVector.size() - 1]->left)
			inorderVector[inorderVector.size() - 1]->lflag = 0;
		else
			inorderVector[inorderVector.size() - 1]->left = inorderVector[inorderVector.size() - 2];
	}

	cout << "BST converted to TBT.\n";
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
	
	inorderMaker(tbt.root);
	tbt.conversion();
	inorder(tbt.root);

	cout << endl;
}
