#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

Node* newNode(int key)
{
	Node* node =new Node();
	node->key =key;
	node->left =nullptr;
	node->right =nullptr;
	node->height =1;

	return (node);	
}

int height(Node* node)
{
	if (!node)
		return 0;

	return node->height;
}

Node* insert(Node* node,int key)
{
	if (!node)
		return (newNode(key));

	if (key<node->key)
		node->left = insert(node->left, key);
	else if (key>node->key)
		node->right =insert(node->right, key);
	else 
		return node;	

	node->height = 1+max(height(node->left), height(node->right));
	return node;
}

void inorder(Node* node)
{
	if (!node)
		return;

	inorder(node->left);
	cout << node->key << " " << node->height << "\n";
	inorder(node->right);
}

int main()
{
	Node* root =nullptr;
	root =insert(root, 45);
	root =insert(root, 90);
	root =insert(root, 40);
	inorder(root);
}
