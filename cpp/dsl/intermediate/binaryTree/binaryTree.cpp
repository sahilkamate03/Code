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


int BinaryTree::height(Node* root)
{
	int h=0;
	if (root==NULL)
		return 0;

	int leftHeight =height(root->left);
	int rightHeight =height(root->right);
	int maxHeight = max(leftHeight, rightHeight);

	h =maxHeight +1;
	return h;
}

void BinaryTree::print_nodes_at_height(Node* root, int current_height, int target_height, bool on_path) {
   if (root == NULL)
        return;
    if (on_path)
        cout << root->data << " ";
    if (current_height == target_height)
        on_path = true;
    print_nodes_at_height(root->left, current_height + 1, target_height, on_path);
    print_nodes_at_height(root->right, current_height + 1, target_height, on_path);
}


void BinaryTree::print_nodes_highest_height(Node* root) {
    if (root == NULL)
        return;
    int tree_height = height(root);
    print_nodes_at_height(root, 1, tree_height,false);
}


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