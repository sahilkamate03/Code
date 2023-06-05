#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	int height;

	Node(int key)
	{
		data =key;
		left =nullptr;
		right =nullptr;
		height =1;
	}
};

int height(Node* node)
{
	if (!node)
		return 0;
	return node->height;
}

int getBalance(Node* node)
{
	if (!node)
		return 0;

	return (height(node->left) -height(node->right));
}

Node* leftRotate(Node* x)
{
	Node* y =x->left;
	Node* T1 =y->right;

	y->right =x;
	x->left =T1;

	x->height =max(height(x->left), height(x->right)) +1;
	y->height =max(height(y->left), height(y->left)) +1;

	return y;
}

Node* rightRotate(Node* x)
{
	Node* y =x->right;
	Node* T1 =y->left;

	y->left =x;
	x->right =T1;

	x->height =max(height(x->left), height(x->right)) +1;
	y->height =max(height(y->left), height(y->left)) +1;

	return y;
}

Node* insert(int key, Node* node)
{
	if (!node)
	{
		return new Node(key);
	}
	
	if (key<node->data)
		node->left =insert(key, node->left);
	else if (key>node->data)
		node->right =insert(key, node->right);
	else 	
		return node;

	node->height =max(height(node->left), height(node->right)) +1;
		
	int balance =getBalance(node);

	//case1 : l rotate
	if (balance>1 && key < node->left->data)
		return leftRotate(node);

	//case 2: r rotate
	if (balance<-1 && key > node->right->data)
		return rightRotate(node);

	//case 3: rl rotate
	if (balance>1 && key > node->left->data)
	{
		node->left =rightRotate(node->left);
		return leftRotate(node);
	}

	//case 4: lr rotate
	if (balance<-1 && key < node->right->data)
	{
		node->right =leftRotate(node->right);
		return rightRotate(node);
	}

	return node;
}

void inorder(Node* node)
{
	if (!node)
		return;
	
	cout << node->data << " ";
	inorder(node->left);
	inorder(node->right);
}

void printCurrentLevel(Node* node, int level)
{
	if (!node)
	{
		cout << " ";
		return;
	}

	if (level==1)
		cout << node->data << " ";

	if (level>1)
	{
		printCurrentLevel(node->left, level-1);
		printCurrentLevel(node->right, level-1);	
	}
}

void printLevelOrder(Node* root)
{
	if (!root)
		return;
	
	int h =height(root);
	for (int i=0; i<=h; i++)
	{
		printCurrentLevel(root, i);
		cout << "\n";
	}
}



int main()
{
	Node* root =nullptr;
	int arr[] ={30, 31, 32, 23, 22, 28, 24, 29, 26, 27};
	int n =sizeof(arr)/ sizeof(int);

	for (int i=0; i<n ;i++)
	{
		root =insert(arr[i], root);
	}
	cout << "Height: ";
	cout << root->height << endl;

	cout << "Level Order: ";
	printLevelOrder(root);
}
