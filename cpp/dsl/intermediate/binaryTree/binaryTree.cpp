#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;

void BinaryTree::insert(int data)
{	
	cout << "Inserting... " << data << "\n";

	Node* newNode = new Node(data);

	if  (root==NULL)
	{
	 	root =newNode;
	 	cout << endl;
		return;
	}

	Node* current= root;
	while (true)
	{
	   	int choice= -1; 
		cout << "Press... \n0:left insertion, 1:right insertion of " << current->data << endl;
		cin>>choice;
		cout << "\n";

		if (choice==0)
		{
			if (!current->left)
			{
				current->left =newNode;
				return;
			}
			current =current->left;
		}
		else if (choice==1)
		{
			if (!current->right)
			{
				current->right =newNode;
				return;	
			}
			current =current->right;
		}
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

void BinaryTree::preOrderTraversal()
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

void BinaryTree::inOrderTraversal()
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

void BinaryTree::postOrderTraversal()
{
	cout << "Press... \n1 -> Recursive 2 -> Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		postOrderTraversalRecursive(this->getRoot());
	else 
		postOrderTraversalIterative();
}

// ------------------------------------------------Traversal Ends---------------------------------------------------------

Node* cloneBinaryTree(Node* root)
{
	if (root == nullptr)
		return nullptr;

	Node* newNode = new Node(root->data);
	newNode->left = cloneBinaryTree(root->left);
	newNode->right = cloneBinaryTree(root->right);

	return newNode;
}

Node* mirrorBinaryTree(Node* root)
{
	if (root == nullptr)
		return nullptr;

	Node* newNode = new Node(root->data);
	newNode->right = mirrorBinaryTree(root->left);
	newNode->left = mirrorBinaryTree(root->right);

	return newNode;
}

bool compareBinaryTree(Node* root1, Node* root2)
{
	if (root1 == NULL && root2 == NULL)	
		return true;

	else if (root1 == NULL || root2 == NULL) 
		return false;

	if (root1->getData() != root2->getData())
		return false;

	if (!compareBinaryTree(root1->getLeft(), root2->getLeft()))
		return false;
	if (!compareBinaryTree(root1->getRight(), root2->getRight()))
		return false;

	return true;
}