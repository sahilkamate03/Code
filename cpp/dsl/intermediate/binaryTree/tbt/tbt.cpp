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

	Node() : data{-1}, left{nullptr}, right{nullptr}, flag_l{true}, flag_r{true} {}
	Node(int _data) : data{_data}, left{nullptr}, right{nullptr}, flag_l{true}, flag_r{true} {}

	friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree
{
private:
	Node *root;
	Node *dummyNode;
	vector<Node *> inorderVector;

public:
	bool isBST_Converted =false;
	bool isTBT =false;
	// ThreadedBinaryTree(): {}
	ThreadedBinaryTree()
	{
		Node *dn = new Node();
		dn->right = dn;
		root = nullptr;
		dummyNode = dn;
	}

	Node *getParentNode(int);
	Node *getRoot() { return root; }
	Node *getDummyNode() const { return dummyNode; }

	//TBT Fxn
	void inOrder();
	void insert(int);
	void remove(int);

	//BST Fxn
	void bst_to_tbt();
	void bstInsert(int);
	void bstInorder();
};

void ThreadedBinaryTree::inOrder()
{
	Node *currentNode = root;
	if (currentNode == nullptr)
	{
		cout << "No element present." << endl;
		return;
	}
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

void ThreadedBinaryTree::bst_to_tbt()
{
	if (!inorderVector.size())
	{
		cout << "BST not initialized." << endl;
		return;
	}

	for (int i = 1; i < inorderVector.size() - 1; i++)
	{
		Node *currentNode = inorderVector[i];
		if (currentNode->left)
			currentNode->flag_l = 0;
		else
			currentNode->left = inorderVector[i - 1];

		if (currentNode->right)
			currentNode->flag_r = 0;
		else
			currentNode->right = inorderVector[i + 1];
	}

	inorderVector[0]->left = dummyNode;
	inorderVector[inorderVector.size() - 1]->right = dummyNode;

	if (inorderVector.size() > 1)
	{
		if (inorderVector[0]->right)
			inorderVector[0]->flag_r = 0;
		else
			inorderVector[0]->right = inorderVector[1];

		if (inorderVector[inorderVector.size() - 1]->left)
			inorderVector[inorderVector.size() - 1]->flag_l = 0;
		else
			inorderVector[inorderVector.size() - 1]->left = inorderVector[inorderVector.size() - 2];
	}

	cout << "BST converted to TBT.\n";
}

void ThreadedBinaryTree::insert(int value)
{
	Node *parentNode = dummyNode;
	Node *currentNode = root;

	if (currentNode == nullptr)
	{
		currentNode = new Node(value);
		currentNode->left = parentNode;
		currentNode->right = parentNode;
		dummyNode->left = currentNode;
		root =currentNode;
		isTBT =true;
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
				newNode->left = currentNode;
				return;
			}
			currentNode = currentNode->right;
		}
	}
}

void ThreadedBinaryTree::bstInorder()
{
	inorderVector.clear();
	stack<Node *> stack;
	Node *currentNode = root;

	if (currentNode == NULL)
	{
		cout << "No element present.\n";
		return;
	}

	while (currentNode != NULL || !stack.empty())
	{
		while (currentNode != NULL)
			stack.push(currentNode),
				currentNode = currentNode->getLeft();

		currentNode = stack.top();
		stack.pop();
		cout << currentNode->getData() << " ",
			inorderVector.push_back(currentNode);

		currentNode = currentNode->getRight();
	}
}

void ThreadedBinaryTree::bstInsert(int value)
{
	Node *newNode = new Node(value);

	if (root == NULL)
	{
		root = newNode;
		return;
	}

	Node *currentNode = root;
	while (currentNode != NULL)
	{
		if (currentNode->data > value)
		{
			if (currentNode->left == NULL)
			{
				currentNode->left = newNode;
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

Node *ThreadedBinaryTree::getParentNode(int value)
{
	Node *currentNode = root;
	Node *parentNode = nullptr;

	if (!root)
		isTBT =false;
		return nullptr;

	while ((!currentNode->flag_l || !currentNode->flag_r) && currentNode->getData() != value)
	{
		parentNode = currentNode;
		if (value < currentNode->getData())
			currentNode = currentNode->getLeft();
		else
			currentNode = currentNode->getRight();
	}

	if (parentNode == nullptr && currentNode->getData() == value)
		return currentNode;

	if (currentNode != nullptr && currentNode->getData() == value)
		return parentNode;

	return nullptr;
}

void ThreadedBinaryTree::remove(int value)
{
	bool isRoot = false;
	Node *currentNode = root;
	Node *parentNode = getParentNode(value);

	if (!parentNode)
	{
		cout << "Not Present\n";
		return;
	}

	if (currentNode->data == value)
		isRoot = true;

	currentNode = parentNode;

	if (parentNode->left != nullptr && parentNode->left->data == value)
		currentNode = parentNode->left;

	else if (parentNode->right != nullptr && currentNode->right->data == value)
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
		if (isRoot)
			root = nullptr;
		return;
	}

	// case 2: when left or right node is present
	// part1 : when left node is present
	if (currentNode->left != nullptr && currentNode->flag_r)
	{
		parentNode->left = currentNode->left;
		parentNode->flag_l = true;
		currentNode->left->right = currentNode->right;
		cout << currentNode->data << "is deleted\n";
		if (isRoot)
		{
			dummyNode->left = currentNode->left;
			root = currentNode->left;
		}
		delete currentNode;
		return;
	}

	// part2 : when right node is present
	if (currentNode->flag_l && currentNode->right != nullptr)
	{
		parentNode->right = currentNode->right;
		parentNode->flag_r = true;
		currentNode->right->left = currentNode->left;
		cout << currentNode->data << " is deleted\n";
		if (isRoot)
		{
			dummyNode->right = currentNode->right;
			root = currentNode->right;
		}
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

void menu(ThreadedBinaryTree &tbt)
{
	cout << "\nMenu\n";
	cout << "1. Insert\n2. Mulitiple Insert\n3. Remove\n4. In Order\n5. BST Insert\n6. BST Inorder\n7. BST to TBT\n8. Exit\n";
	cout << "\nEnter your choice: ";
	int choice; cin>>choice;
	int temp, n;

	switch(choice)
	{
	case 1:
		cout << "Enter element: ";
		cin>> temp;
		tbt.insert(temp);
		break;

	case 2:
		cout << "Enter no of element: ";
		cin >>n;
		for(int i=0; i<n; i++)
		{
			cout << i+1 <<". ";
			cin >>temp;
			tbt.insert(temp);
		}
		break;

	case 3:
		cout << "Enter element to remove: ";
		cin >> temp;
		tbt.remove(temp);
		break;

	case 4:
		cout << "Inorder: ";
		tbt.inOrder();
		break;

	case 5:
		if (tbt.isTBT)
		{
			cout << "TBT initialized! Clear TBT to use the feature.\n";
		} else{
			cout << "Enter element: ";
			cin >> temp;
			tbt.bstInsert(temp);
		}
		break;

	case 6:
		if (tbt.isTBT)
		{
			cout << "TBT initialized! Clear TBT to use the feature.\n";
		} else{
			cout << "BST Inorder: ";
			if (!tbt.isBST_Converted)
				tbt.bstInorder();
			else 
				cout << "Converted to TBT.\n";
		}
		break;

	case 7:
		tbt.bst_to_tbt();
		tbt.isBST_Converted =true;
		break;

	default:
		exit(0);

	}

}

int main()
{
	ThreadedBinaryTree tbt;
	cout << "ThreadedBinaryTree\n";
	while(true)
		menu(tbt);
}