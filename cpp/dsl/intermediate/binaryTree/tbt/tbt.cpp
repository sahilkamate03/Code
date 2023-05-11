#include <bits/stdc++.h>
using namespace std;

class Node
{
private:
	int data;
	Node *left;
	Node *right;

	// if true thread exists
	bool flag_l;
	bool flag_r;

public:
	Node *getLeft() const { return left; }
	Node *getRight() const { return right; }
	int getData() const { return data; }

	Node() : data{-1}, left{nullptr}, right{nullptr}, flag_l{0}, flag_r{0} {}
	Node(int _data) : data{_data}, left{nullptr}, right{nullptr}, flag_l{1}, flag_r{1} {}
	Node(Node *dn, Node *root) : data{5}, left{root}, flag_l{0}, flag_r{1} { right = dn; }

	friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree
{
private:
	Node *root;
	Node *dummyNode;
	vector<Node *> inorderVector;

public:
	// ThreadedBinaryTree(): {}
	ThreadedBinaryTree()
	{
		Node *rootNode = new Node;
		Node *dm = new Node(dm, rootNode);

		root = rootNode;
		dummyNode = dm;
	}

	void inOrder();
	void inOrderMaker(Node *);
	void inOrderRecursive(Node *);
	void insert(int);
	void remove(int);
	Node *getParentNode(int);
	Node *getRoot() const { return root; }
	Node *getDummyNode() const { return dummyNode; }
};

void ThreadedBinaryTree::inOrder()
{
	Node *currentNode = root;
	if (currentNode == nullptr)
		return;
	while (currentNode->flag_l == 0)
		currentNode = currentNode->left;

	while (currentNode != dummyNode)
	{
		cout << currentNode->data << " ";

		if (currentNode->flag_r)
			currentNode = currentNode->right;

		else
		{
			currentNode = currentNode->right;
			while (currentNode->flag_l == 0)
				currentNode = currentNode->left;
		}
	}
}

void ThreadedBinaryTree::inOrderRecursive(Node *currentNode)
{
	if (currentNode == NULL)
		return;

	inOrderRecursive(currentNode->getLeft());
	cout << currentNode->getData() << " ";
	inOrderRecursive(currentNode->getRight());
}

void ThreadedBinaryTree::inOrderMaker(Node *currentNode)
{
	if (currentNode == NULL)
		return;

	inOrderMaker(currentNode->getLeft());
	inorderVector.push_back(currentNode);
	inOrderMaker(currentNode->getRight());
}

void ThreadedBinaryTree::insert(int value)
{
	Node *parentNode = dummyNode;
	Node *currentNode = root;

	if (currentNode->data == -1)
	{
		currentNode->data = value;
		currentNode->left = parentNode;
		currentNode->right = parentNode;
		currentNode->flag_l = 1;
		currentNode->flag_r = 1;
		return;
	}

	Node *newNode = new Node(value);

	while (currentNode != dummyNode)
	{
		parentNode = currentNode;
		if (currentNode->data > value)
		{
			if (currentNode->flag_l)
			{
				newNode->left = currentNode->left;

				currentNode->left = newNode;
				currentNode->flag_l = 0;

				newNode->right = currentNode;
				return;
			}
			currentNode = currentNode->left;
		}

		else
		{
			if (currentNode->flag_r)
			{
				newNode->right = currentNode->right;

				currentNode->right = newNode;
				currentNode->flag_r = 0;

				newNode->left = currentNode;
				return;
			}

			currentNode = currentNode->right;
		}
	}
}

Node *ThreadedBinaryTree::getParentNode(int value)
{
	Node *currentNode = root;
	Node *parentNode = NULL;

	while (currentNode != dummyNode && currentNode->getData() != value)
	{
		parentNode = currentNode;
		if (value < currentNode->getData())
			currentNode = currentNode->getLeft();
		else
			currentNode = currentNode->getRight();
	}

	if (parentNode == NULL && currentNode->getData() == value)
		return currentNode;

	if (currentNode != NULL && currentNode->getData() == value)
		return parentNode;

	return NULL;
}

void ThreadedBinaryTree::remove(int value)
{
	Node *currentNode = root;
	Node *parentNode = getParentNode(value);

	if (!parentNode)
	{
		cout << "Not Present\n";
		return;
	}

	currentNode = parentNode;

	if (parentNode->left != NULL && parentNode->left->data == value)
		currentNode = parentNode->left;

	else if (parentNode->right != NULL && currentNode->right->data == value)
		currentNode = parentNode->right;

	// case 1: when both the left and right nodes are not present
	if (currentNode->flag_l && currentNode->flag_r)
	{
		if (parentNode->left == currentNode)
			parentNode->left = currentNode->left,
			parentNode->flag_l = true;

		else
			parentNode->right = currentNode->right,
			parentNode->flag_r = true;

		cout << currentNode->data << " is deleted\n";
		delete currentNode;
		return;
	}

	// case 2: when left or right node is present
	// part1 : when left node is present
	if (currentNode->left != NULL && currentNode->right == parentNode)
	{
		parentNode->left = currentNode->left;
		parentNode->flag_l = true;
		currentNode->left->right = currentNode->right;
		cout << currentNode->data << "is deleted\n";
		delete currentNode;
		return;
	}

	// part2 : when right node is present
	if (currentNode->left == parentNode && currentNode->right != NULL)
	{
		parentNode->right = currentNode->right;
		parentNode->flag_r = true;
		currentNode->right->left = currentNode->left;
		cout << currentNode->data << " is deleted\n";
		delete currentNode;
		return;
	}

	// case 3: when both left and right node are present
	Node *replacementNode = currentNode->right;
	Node *parentReplacementNode = replacementNode;

	while (replacementNode->flag_l != true)
		parentReplacementNode = replacementNode,
		replacementNode = replacementNode->left;

	cout << currentNode->data << " is deleted\n";
	currentNode->data = replacementNode->data;

	if (replacementNode == parentReplacementNode)
	{
		currentNode->right = replacementNode->right;
		currentNode->flag_r = 1;
		delete replacementNode;
		return;
	}

	if (replacementNode->flag_r == true)
	{
		parentReplacementNode->left = replacementNode->left;
		delete replacementNode;
		return;
	}

	replacementNode->data = replacementNode->right->data;
	replacementNode->right = replacementNode->right->right;
	delete replacementNode->right;
	return;
}

int main()
{
	ThreadedBinaryTree tbt;
	tbt.insert(10);
	tbt.insert(12);
	tbt.insert(11);
	tbt.insert(14);
	tbt.insert(15);
	tbt.inOrder();
	tbt.remove(10);
	tbt.inOrder();
}