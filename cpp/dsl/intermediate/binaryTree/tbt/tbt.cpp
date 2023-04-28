#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	int data;
	
	Node* left;
	Node* right;

	//if true thread exists
	bool flag_l; 
	bool flag_r;

public:

    Node* getLeft() const {return getLeft;}
    Node* getRight() const {return right;}


	Node() : data{-1}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}
	Node(int _data) : data{_data}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}

	friend class DummyNode;
	friend class ThreadedBinaryTree;
};

class DummyNode
{
private:
	string data;
	Node* left;
	DummyNode* right;

	bool flag_l;
	bool flag_r;

public:
	DummyNode() : data{""}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}
	DummyNode(DummyNode* dn, Node* root) : data{""}, left{root}, flag_l{0}, flag_r{1} {right =dn;}

	friend class Node;
	friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree 
{
private:
	Node* root;
	Node* dummyNode;
	vector<Node*> inorderVector;

public:
	// ThreadedBinaryTree(): {}
	ThreadedBinaryTree() 	
	{
		Node* rootNode =new Node;
		DummyNode* dm =new DummyNode(dm, rootNode);
		root =rootNode;
	}

	void inOrderMaker(Node*);
	void insert(int);
};

void ThreadedBinaryTree::inOrderMaker(Node* currentNode)
{
	if(currentNode == NULL)
		return;

	inOrderMaker(currentNode->getLeft());
	inorderVector.push_back(currentNode);
	inOrderMaker(currentNode->getRight());
}

void ThreadedBinaryTree::insert(int value)
{
	if (root->data == -1)
	{
		root->data =value;
	}

	Node* newNode =new Node(value);

	Node* currentNode =root;
	while (currentNode!=nullptr)
	{
		if (currentNode->data > value)
		{
			if (currentNode->left == nullptr)
			{
				currentNode->left =newNode;
				return;
			}
			currentNode = currentNode->left;
		}
		else 
		{
			if (currentNode->right == nullptr)
			{
				currentNode->right = newNode;
				return;
			}
			currentNode = currentNode->right;
		}
	}	
}


int main()
{

}
