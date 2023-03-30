#include <bits/stdc++.h>
#include "binaryTree.h"
using namespace std;

void menuBST(BinarySearchTree& bt)
{
	//initialization
	int value;

	Node* cloneBinaryTreeNode;
	BinaryTree clone;

	Node* mirrorBinaryTreeNode;
	BinaryTree mirror;

	int choice; 

	while (true)
	{
		cout << "\nBinary Search Tree\n";	
		cout << "\n1. Insert\n2. Pre-Order\n3. In-Order\n4. Post-Order\n";
		cout << "5. Height\n6. Clone\n7. Mirror\n8. Remove\n9. Exit\n";
		cout << "\nEnter Choice: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			cout << "\nEnter number: "; cin>> value;
			bt.insert(value);
			break;
		case 2:
			bt.preOrderTraversal();
			break;
		case 3:
			bt.inOrderTraversal();
			break;
		case 4:
			bt.postOrderTraversal();
			break;
		case 5:
			bt.height(bt.getRoot());
			break;
		case 6:
			cloneBinaryTreeNode =cloneBinaryTree(bt.getRoot());
			clone.setRoot(cloneBinaryTreeNode);
			clone.preOrderTraversal();
			break;
		case 7:
			mirrorBinaryTreeNode =mirrorBinaryTree(bt.getRoot());
			mirror.setRoot(mirrorBinaryTreeNode);
			mirror.preOrderTraversal();
			break;
		case 8:
			cout << "\nEnter Value: ";cin >> value;
			bt.remove(value);
			break;
		default:
			return;
		}
	}
}

void menuBT(BinaryTree& bt)
{
	//initialization
	int value;

	Node* cloneBinaryTreeNode;
	BinaryTree clone;

	Node* mirrorBinaryTreeNode;
	BinaryTree mirror;


	int choice; 

	while (true)
	{
		cout << "\nBinary Tree\n";
		cout << "\n1. Insert\n2. Pre-Order\n3. In-Order\n4. Post-Order\n";
		cout << "5. Height\n6. Clone\n7. Mirror\n8. Exit\n";
		cout << "\nEnter Choice: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout << "\nEnter number: "; cin>> value;
			bt.insert(value);
			break;
		case 2:
			bt.preOrderTraversal();
			break;
		case 3:
			bt.inOrderTraversal();
			break;
		case 4:
			bt.postOrderTraversal();
			break;
		case 5:
			bt.height(bt.getRoot());
			break;
		case 6:
			cloneBinaryTreeNode =cloneBinaryTree(bt.getRoot());
			clone.setRoot(cloneBinaryTreeNode);
			clone.preOrderTraversal();
			break;
		case 7:
			mirrorBinaryTreeNode =mirrorBinaryTree(bt.getRoot());
			mirror.setRoot(mirrorBinaryTreeNode);
			mirror.preOrderTraversal();
			break;
		default:
			return;
		}
	}
}

void mainMenu()
{
	BinaryTree bt1;
	BinarySearchTree bst1;

	cout << "\n1.BinaryTree\n2.BinarySearchTree\n3.Exit\n";
	cout << "\nEnter choice: ";

	int choice; cin>>choice;
	if (choice==1)
		menuBT(bt1);
	else if (choice==2)
		menuBST(bst1);
	else 
		exit(0);
}

int main()
{
	while (true)
		mainMenu();
	return 0;
}
