#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int _data)
	{
		data =_data;
		left =nullptr;
		right =nullptr;
	}

	friend class BST;
};

class BST
{
public:
	Node* root;
	
	BST()
	{
		root =nullptr;
	}

	void insert(int);
	void remove(int);
};

void BST::insert(int key)
{
	Node* newNode =new Node(key);

	if (!root)
	{
		root =newNode;
		return;
	}
	
	Node* parentNode =NULL;

	Node* currentNode =root;
	while (true)
	{
		if (!currentNode)
		{
			if (key < parentNode->data)
				parentNode->left =newNode;
			else 
				parentNode->right =newNode;
			return;
		}

		parentNode =currentNode;
	
		if (key<currentNode->data)
			currentNode =currentNode->left;
		else 
			currentNode =currentNode->right;
	}	
}

void inorder(Node* node)
{
	if (!node)
		return;
	inorder(node->left);
	cout << node->data << " " << std::flush;
	inorder(node->right);
}

int height(Node* node)
{
	if (!node)
		return 0;

	int left =height(node->left);
	int right =height(node->right);
	
	return max(left, right) +1;
}

void BST::remove(int key)
{
	Node* parentNode =root;
	Node* currentNode =root;

	while(true)
	{
		if (!currentNode)
		{
			cout << "Key is not present\n";
			return;
		}
		if (key == currentNode->data)
			break;

		parentNode =currentNode;
		if (key<currentNode->data)
			currentNode =currentNode->left;
		else
			currentNode =currentNode->right;
	
	}
	
	//case 1: no nodes
	if (!currentNode->left && !currentNode->right)		
	{
		delete currentNode;
		
		if (parentNode==currentNode)
		{
			root =nullptr;
			return;
		}	

		if (key < parentNode->data)
			parentNode->left =nullptr;
		else parentNode->right =nullptr;
		
		return; 
	}

	//case 2: 1 node
	
	//part 1: left
	if (currentNode->left && !currentNode->right)
	{
		if (parentNode==currentNode)
		{
			root =currentNode->left;
			delete currentNode;
			return;
		}	
		if (parentNode->data > currentNode->data)
			parentNode->left =currentNode->left;
		else 
			parentNode->right =currentNode->left;

		delete currentNode;
		return;
	}

	//part 2: right	
	if (!currentNode->left && currentNode->right)
	{
		if (parentNode==currentNode)
		{
			root =currentNode->right;
			delete currentNode;
			return;
		}	
		if (currentNode->data < parentNode->data) 
			parentNode->left =currentNode->right;
		else 
			parentNode->right =currentNode->right;

		delete currentNode;
		return;
	}

	//case 3: both are present
	
	Node* replacementNode =currentNode->right;
	Node* parentReplacementNode =currentNode;
	while(replacementNode->left)
		parentReplacementNode =replacementNode,
		replacementNode =replacementNode->left;
	
	currentNode->data =replacementNode->data;
	
	if (replacementNode->right)
	{
		parentReplacementNode->left =replacementNode->right;
		delete replacementNode;
		return;
	}
	
	if (replacementNode == parentReplacementNode)
	{
		currentNode->right =nullptr;
		delete replacementNode;
		return;
	}

	parentReplacementNode ->left =nullptr;
	delete replacementNode;
}

void inorderI(Node* root)
{
	Node* node =root;

	stack<Node*> st;
	
	while(!node || !st.empty())
	{
		while (!node)
		{
			st.push(node);
			node =node->left;
		}
		node =st.top();
		st.pop();
		cout << node->data << " ";
		node =node->right;
	}	
	cout << "\n";
}

void preOrderI(Node* root)
{
	Node* node =root;
	stack<Node*> st;
	st.push(node);

	while(!st.empty())
	{
		cout << st.top()->data << " ";
		node =st.top();
		st.pop();
		if(node->right)
			st.push(node->right);
		if (node->left)
			st.push(node->left);
	}
	
	cout << "\n";
}

void postOrderI(Node* root)
{
	stack<Node*> st1;
	stack<Node*> st2;
	
	Node* node =root;
	st1.push(node);

	while(!st1.empty())
	{
		node =st1.top();
		st2.push(node);
		st1.pop();

		if (node->left)
			st1.push(node->left);
		if (node->right)
			st1.push(node->right);
	}

	while(!st2.empty())
	{
		node =st2.top();
		st2.pop();
		cout << node->data << " ";
	}
	cout << "\n";

}

int k=0;
int n;
Node* constructTree(int in[], int pre[], int i, int j)
{
	if (i>j || k>=n)
		return nullptr;

	int v =pre[k++];

	int x=i;
	for (int k=i; k<=j; k++)
	{
		if (in[k]==v)
		{
			x=k;
			break;
		}
	}

	Node* currentNode =new Node(v);
	currentNode->left =constructTree(in, pre, i, x-1);
	currentNode->right =constructTree(in, pre, x+1, j);

	return currentNode;
}

int main()
{
	BST bst;
	bst.insert(14);	
	bst.insert(6);	
	bst.insert(4);
	bst.insert(10);	
	bst.insert(8);	
	bst.insert(9);	
	bst.insert(16);
	bst.insert(15);
	
	int in[] ={2,3,4,6,7,9,13,15,17,18,20};
	int pre[] ={15,6,3,2,4,7,13,9,18,17,20};
    n=sizeof(in)/sizeof(int);

	inorder(constructTree(in, pre, 0, n));
	k =0;
	cout << "\n";
	return 0;
	postOrderI(bst.root);
	inorder(bst.root);	
	cout << "\n";

	cout <<	height(bst.root);
	cout << "\n";
	
	int d;
	while(bst.root)	
	{
	cout << "> ";
	cin >> d;

	bst.remove(d);
	inorder(bst.root);
	cout << "\n";
	}
}
