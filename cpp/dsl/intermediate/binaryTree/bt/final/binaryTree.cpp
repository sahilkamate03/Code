#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;

void BinaryTree::insert(int data)
{	
	cout << "\nInserting: " << data << "\n";

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

void preOrderTraversalIterative(Node* root)
{
	stack<Node*> stack;
	Node* currentNode =root;
	cout << "pre\n";
	while(currentNode!=NULL || !stack.empty() )
	{
		while (currentNode != NULL)
			stack.push(currentNode),
			currentNode =currentNode->getLeft();

		currentNode =stack.top();
		cout << currentNode->getData() << " ";
		stack.pop();

		currentNode =currentNode->getRight();
	}
}

void BinaryTree::preOrderTraversal()
{
	cout << "\n1. Recursive 2. Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		preOrderTraversalRecursive(this->getRoot());
	else 
		preOrderTraversalIterative(this->root);
}

void inOrderTraversalRecursive(Node* currentNode)
{
	if(currentNode == NULL)
		return;

	inOrderTraversalRecursive(currentNode->getLeft());
	cout << currentNode->getData() << " ";
	inOrderTraversalRecursive(currentNode->getRight());
}

void inOrderTraversalIterative(Node* root)
{
	stack<Node*> stack;
	Node* currentNode =root;

	while(currentNode!=NULL || !stack.empty() )
	{
		while (currentNode != NULL)
			stack.push(currentNode),
			currentNode =currentNode->getLeft();

		currentNode =stack.top();
		stack.pop();
		cout << currentNode->getData() << " ",

		currentNode =currentNode->getRight();
	}
}

void BinaryTree::inOrderTraversal()
{
	cout << "\n1. Recursive 2. Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		inOrderTraversalRecursive(this->getRoot());
	else 
		inOrderTraversalIterative(this->root);
}

void postOrderTraversalRecursive(Node* currentNode)
{
	if (currentNode==NULL)
		return;

	postOrderTraversalRecursive(currentNode->getLeft());
	postOrderTraversalRecursive(currentNode->getRight());
	cout << currentNode->getData() << " ";
}

void postOrderTraversalIterative(Node* root)
{
	stack<Node*> stack;
	Node* currentNode =root;

	while(currentNode!=NULL || !stack.empty() )
	{
		while (currentNode != NULL)
			stack.push(currentNode),
			currentNode =currentNode->getLeft();

		currentNode =stack.top();
		stack.pop();
		cout << currentNode->getData() << " ",

		currentNode =currentNode->getRight();
	}
}

void BinaryTree::postOrderTraversal()
{
	cout << "\n1. Recursive 2. Iterative: ";
	int choice; cin>>choice;

	if (choice==1)
		postOrderTraversalRecursive(this->getRoot());
	else 
		postOrderTraversalIterative(this->root);
}

// ------------------------------------------------Traversal Ends---------------------------------------------------------


// ------------------------------------------------Miscellenous Function--------------------------------------------

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

Node* cloneBinaryTree(Node* root)
{
	if (root == NULL)
		return NULL;

	Node* newNode = new Node(root->data);
	newNode->left = cloneBinaryTree(root->left);
	newNode->right = cloneBinaryTree(root->right);

	return newNode;
}

Node* mirrorBinaryTree(Node* root)
{
	if (root == NULL)
		return NULL;

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

// ------------------------------------------Miscellenous Function Ends--------------------------------------------


// ----------------------------------------------------BST-----------------------------------------------------------


void BinarySearchTree::insert(int value)
{
	Node* newNode =new Node(value);

	if (root==NULL)
	{
		root =newNode;
		return;
	}

	Node* currentNode =root;
	while (currentNode!=NULL)
	{
		if (currentNode->data > value)
		{
			if (currentNode->left == NULL)
			{
				currentNode->left =newNode;
				return;
			}
			currentNode = currentNode->left;
		}
		else 
		{
			if (currentNode->right == NULL)
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
		if (currentNode == NULL)
			return false;

		if (currentNode->data == value)
			return true;

		if (value < currentNode->data)
			currentNode = currentNode->left;
		else 
			currentNode = currentNode->right;
	}	
}

Node* getParentNode(Node* root, int value)
{
	Node* currentNode =root;
	Node* parentNode =NULL;
	while (currentNode!=NULL && currentNode->getData() != value)
	{
		parentNode =currentNode;
		if (value < currentNode->getData())
			currentNode =currentNode->getLeft();
		else
			currentNode =currentNode->getRight();
	}

	if (parentNode==NULL && currentNode->getData() == value)
		return currentNode;

	if (currentNode!=NULL && currentNode->getData() == value)
		return parentNode;

	return NULL;
}

void BinarySearchTree::remove(int value)
{
	Node* currentNode =this->root;
	
	Node* parentNode =getParentNode(currentNode, value);
	if (!parentNode)
	{
		cout << "Not Present\n";
		return;
	}

	currentNode =parentNode;
	if (parentNode->left != NULL && parentNode->left->data == value)
		currentNode =parentNode->left;
	else if (parentNode->right != NULL && currentNode->right->data == value)
		currentNode =parentNode->right;

	// case 1: when both the left and right nodes are not present
	if (!currentNode->left && !currentNode->right)
	{
		if (parentNode->left == currentNode)
			parentNode->left =NULL;
		else 
			parentNode->right =NULL;

		cout << currentNode->data << " is deleted\n";
		delete currentNode;
		return;
	}

	// case 2: when left or right node is present 
	// part1 : when left node is present
	if (currentNode->left!=NULL && currentNode->right==NULL)
	{
		if (parentNode->left == currentNode)
			parentNode->left =currentNode->left;
		else 
			parentNode->right =currentNode->left;

		cout << currentNode->data << "is deleted\n";
		delete currentNode;
		return;
	}

	// part2 : when right node is present
	if (currentNode->left==NULL && currentNode->right!=NULL)
	{
		if (parentNode->left == currentNode)
			parentNode->left =currentNode->right;
		else 
			parentNode->right =currentNode->right;

		cout << currentNode->data << " is deleted\n";
		delete currentNode;
		return;
	}

	// case 3: when both left and right node are present
	Node* replacementNode =currentNode->right;
	Node* parentReplacementNode;
	while (replacementNode->left != NULL)
		parentReplacementNode =replacementNode,
		replacementNode =replacementNode->left;

	cout << currentNode->data << " is deleted\n";
	currentNode->data =replacementNode->data;
	if (replacementNode->right == NULL)
	{
		delete replacementNode;
		parentReplacementNode->left =NULL;
		return;
	}

	replacementNode->data =replacementNode->right->data;
	replacementNode->right =NULL;
	delete replacementNode->right;

	return;
}