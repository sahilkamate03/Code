#include <bits/stdc++.h>
#include "bst.h"
using namespace std;


void BinarySearchTree::insert(int value)
{
	Node* newNode =new Node(value);

	if (root==NULL)
	{
		root =newNode;
		return;
	}

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

bool BinarySearchTree::search(int value)
{
	Node* currentNode=root;

	while (true)
	{
		if (currentNode == nullptr)
			return false;

		if (currentNode->data == value)
			return true;

		if (value < currentNode->data)
			currentNode = currentNode->left;
		else 
			currentNode = currentNode->right;
	}	
}

// ------------------------------------------------Traversal Starts---------------------------------------------------------

void preOrderTraversalRecursive(Node* currentNode)
{
	if (currentNode == NULL)
		return;

	cout << currentNode->getData() << " ";

	preOrderTraversalRecursive(currentNode->getLeft());
	preOrderTraversalRecursive(currentNode->getRight());
}

void preOrderTraversalIterative()
{
	cout << "preOrderTraversalIterative" << endl;
}

void BinarySearchTree::preOrderTraversal()
{
	cout << "Press... \n1 -> Recursive 2 -> Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		preOrderTraversalRecursive(this->getRoot());
	else 
		preOrderTraversalIterative();
}

void inOrderTraversalRecursive(Node* currentNode)
{
	if(currentNode == NULL)
		return;

	inOrderTraversalRecursive(currentNode->getLeft());
	cout << currentNode->getData() << " ";
	inOrderTraversalRecursive(currentNode->getRight());
}

void inOrderTraversalIterative()
{
	cout << "inOrderTraversalIterative" << endl;
}

void BinarySearchTree::inOrderTraversal()
{
	cout << "Press... \n1 -> Recursive 2 -> Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		inOrderTraversalRecursive(this->getRoot());
	else 
		inOrderTraversalIterative();
}

void postOrderTraversalRecursive(Node* currentNode)
{
	if (currentNode==NULL)
		return;

	postOrderTraversalRecursive(currentNode->getLeft());
	postOrderTraversalRecursive(currentNode->getRight());
	cout << currentNode->getData() << " ";
}

void postOrderTraversalIterative()
{
	cout << "postOrderTraversalIterative" << endl;
}

void BinarySearchTree::postOrderTraversal()
{
	cout << "Press... \n1 -> Recursive 2 -> Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		postOrderTraversalRecursive(this->getRoot());
	else 
		postOrderTraversalIterative();
}

// ------------------------------------------------Traversal Ends---------------------------------------------------------


